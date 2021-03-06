#include "bluetoothgui.h"
#include "ui_bluetoothgui.h"
#include <QTimer>


BluetoothGUI::BluetoothGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BluetoothGUI), localDevice(new QBluetoothLocalDevice)
{
    ui->setupUi(this);

    // Can only change focus with mouse clicks
    setFocusPolicy(Qt::ClickFocus);
    // Allow graphical widget to accept focus by mouseclick
    ui->openGLWidget->setFocusPolicy(Qt::ClickFocus);
    ui->command_line->setFocusPolicy(Qt::ClickFocus);
    ui->centralWidget->setFocusPolicy(Qt::ClickFocus);
    ui->Q_value->setFocusPolicy(Qt::ClickFocus);
    ui->R_value->setFocusPolicy(Qt::ClickFocus);

    // Drawing variables
    elapsed = 0;
    ui->openGLWidget->setAutoFillBackground(false);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &BluetoothGUI::animate);
    timer->start(50);
    image_scale = 1;
    setScaleText();
    translation.setX(0);
    translation.setY(0);
    draw_position = false;
    meas_path = "/Users/timfornell/Documents/GitHub/BluetoothGUI/Source/measurements.txt"; // File containing received measurements
    est_path = "/Users/timfornell/Documents/GitHub/BluetoothGUI/Source/estimates.txt"; // File containing received measurements
    cov_path = "/Users/timfornell/Documents/GitHub/BluetoothGUI/Source/covariaces.txt"; // File containing received measurements
    path = "/Users/timfornell/Documents/GitHub/BluetoothGUI/Source/output_file.txt"; // File containing estimates produced by KF
    brush.setEstPath(est_path);
    brush.setCovPath(cov_path);
    new_session = true;
    save_measurements = false;

    // Initialise ekf
    qDebug() << "Initialize EKF";
    ekf_enabled = false;
    ekf = KalmanFilter("CA", "accel", 1, 0.05, 1);
    // Set states in brush
    brush.setStates(ekf.getStates());
    ekf.setMeasPath(meas_path);
    ekf.setEstPath(est_path);
    ekf.setCovPath(cov_path);
    // Time for EKF
    ekf_timer = new QTimer(this);
    connect(ekf_timer, SIGNAL(timeout()), this, SLOT(runKalmanFilter()));
    ekf_timer->start(1000); // EKF runs at Ts = 2s

    // Bluetooth vairables
    timeout = 2000;
    robot_direction = "still";

    ui->connected_device->setText("None");
    ui->draw_positions->setCheckState(Qt::Unchecked);
    ui->enable_ekf->setCheckState(Qt::Unchecked);
    ui->save_meas->setCheckState(Qt::Unchecked);
    ui->Q_value->setText(QString::number(ekf.getQ()));
    ui->R_value->setText(QString::number(ekf.getR()));

    // Connect Signals to appropriate Slots

    // Connect map signals
    connect(ui->actionReset_translation, SIGNAL(triggered()), this, SLOT(resetTranslation()));
    connect(ui->actionReset_zoom, SIGNAL(triggered()), this, SLOT(resetZoom()));
    connect(ui->draw_positions, SIGNAL(toggled(bool)), this, SLOT(drawEstimatedPositions(bool)));

    // Connect buttons in GUI to appropriate functions
    connect(ui->search, SIGNAL(released()), this, SLOT(startScan()));
    connect(ui->connect, SIGNAL(released()), this, SLOT(connectToDevice()));
    connect(ui->send_command, SIGNAL(released()), this, SLOT(sendCommand()));
    connect(ui->disconnect, SIGNAL(released()), this, SLOT(disconnectDevice()));
    connect(ui->enable_ekf, SIGNAL(toggled(bool)), this, SLOT(enableEKF(bool)));
    connect(ui->save_meas, SIGNAL(toggled(bool)), this, SLOT(saveMeasurements(bool)));

    //     Check if Bluetooth is available on this device
    if (localDevice->isValid()) {
        // Turn Bluetooth on
        localDevice->powerOn();

        // Read local device name
        localDeviceName = localDevice->name();

        // Make it visible to others
        localDevice->setHostMode(QBluetoothLocalDevice::HostDiscoverable);

        // Get connected devices
        QList<QBluetoothAddress> remotes;
        remotes = localDevice->connectedDevices();

        qDebug() << "My name is: " << localDeviceName;
        int n = remotes.length();
        qDebug() << "Connected to " << n << " device(s): ";
        for(int i = 0; i < n; i ++){
            qDebug() << remotes.at(i) << ", ";
        }
    }
}

BluetoothGUI::~BluetoothGUI()
{
    delete ui;
}

/*****************************************************************
 * Functions regarding input from mouse and keyboard
 *
 * **************************************************************/

/*
 * Handles events produced when pressing a key
 * */
void BluetoothGUI::keyPressEvent(QKeyEvent *event){
    // If mainwindow has focus
    //qDebug() << "Key pressed: " << event->key();
    if(ui->centralWidget->hasFocus()){
        //qDebug() << "Mainwindow has focus";
        switch(event->key()){
        case Qt::Key_W:
        {
            if(robot_direction != "W"){
                robot_direction = "W";
                buttons_pressed.append(Qt::Key_W);
                QString command("W");
                sendToDevice(command);
                qDebug() << "Robot direction: " << robot_direction;
            }

            break;
        }
        case Qt::Key_D:
        {
            if(robot_direction != "D"){
                robot_direction = "D";
                buttons_pressed.append(Qt::Key_D);
                QString command("D");
                sendToDevice(command);
                qDebug() << "Robot direction: " << robot_direction;
            }

            break;
        }
        case Qt::Key_A:
        {
            if(robot_direction != "A"){
                robot_direction = "A";
                buttons_pressed.append(Qt::Key_A);
                QString command("A");
                sendToDevice(command);
                qDebug() << "Robot direction: " << robot_direction;
            }

            break;
        }
        case Qt::Key_S:
        {
            if(robot_direction != "S"){
                robot_direction = "S";
                buttons_pressed.append(Qt::Key_S);
                QString command("S");
                sendToDevice(command);
                qDebug() << "Robot direction: " << robot_direction;
            }

            break;
        }
        default:
            qDebug() << "Unknown key pressed";
            break;
        }
    }
}

/*
 * Handles events produced when releasing a key
 * */
void BluetoothGUI::keyReleaseEvent(QKeyEvent *event){
    int key =  event->key();
    if(ui->centralWidget->hasFocus()){
        QString command;
        bool direction_changed = false;

        if((key == Qt::Key_W || key == Qt::Key_A || key == Qt::Key_S || key == Qt::Key_D)
                && robot_direction != "still"){
            // The buttons must have been pressed previously -> remove it from buttons_pressed
            removePressedButton(key);

            if(!buttons_pressed.isEmpty()){
                // Send the last pressed button as command
                key = buttons_pressed.last();
                switch(key){
                case Qt::Key_W:{
                    qDebug() << "W is the last button";
                    if(robot_direction != "W"){
                        command = "W";
                        robot_direction = "W";
                        direction_changed = true;
                    }
                    break;
                }
                case Qt::Key_A:{
                    qDebug() << "A is the last button";
                    if(robot_direction != "A"){
                        command = "A";
                        robot_direction = "A";
                        direction_changed = true;
                    }
                    break;
                }
                case Qt::Key_S:{
                    qDebug() << "S is the last button";
                    if(robot_direction != "S"){
                        command = "S";
                        robot_direction = "S";
                        direction_changed = true;
                    }
                    break;
                }
                case Qt::Key_D:{
                    qDebug() << "D is the last button";
                    if(robot_direction != "D"){
                        command = "D";
                        robot_direction = "D";
                        direction_changed = true;
                    }
                    break;
                }
                default:
                    // Should not be here
                    break;
                }
            }else{
                command = "STOP";
                robot_direction = "still";
                direction_changed = true;
            }

            if(direction_changed){
                sendToDevice(command);
            }
        }
    }else if(ui->command_line->hasFocus()){
        qDebug() << "Command line has focus";
        if(key == Qt::Key_Return){
            // Send the command
            sendCommand();
        }
    }else if(ui->Q_value->hasFocus() && key == Qt::Key_Return){
        QString value = ui->Q_value->text();

        if(!ekf_enabled){
            ekf.setQ(value.toDouble());
        }else{
            qDebug() << "Can only be performed when ekf is not running";
        }

        ui->Q_value->setText(QString::number(ekf.getQ()));
    }else if(ui->R_value->hasFocus() && key == Qt::Key_Return){
        QString value = ui->R_value->text();
        if(!ekf_enabled){
            ekf.setR(value.toDouble());
        }else{
            qDebug() << "Can only be performed when ekf is not running";
        }

        ui->R_value->setText(QString::number(ekf.getR()));
    }
}

/*
 * Removes key from list of previously pressed keys
 * */
void BluetoothGUI::removePressedButton(int key){
    qDebug() << "Remove button";
    for(int i = 0; i < buttons_pressed.size(); i++){
        // Only one instance of each button can be present, find it and remove it
        if(buttons_pressed.at(i) == key){
            buttons_pressed.removeAt(i);
        }
    }
}

/*
 * Handles events produces when scrolling mouse wheel
 * */
void BluetoothGUI::wheelEvent(QWheelEvent *event){
    // If map is in focus
    if(ui->openGLWidget->hasFocus()){
        // Calculate the number of degrees the wheel has been turned
        QPoint numDegrees = event->angleDelta() / 8 / 15;
        int scrolls = numDegrees.y();
        // If the image is larger than 0.01 and the direction is positive
        if(image_scale > 0.01 || scrolls > 0){
            image_scale += 0.01*scrolls;
        }
        // If the directions is negative or the scale somehow ended up smaller than 0.01
        else if(scrolls < 0 && image_scale <= 0.01){
            image_scale = 0.01;
        }
        qDebug() << "Scale: " << image_scale;

        setScaleText();
    }
}

/*
 * Handles events produces when pressing any mouse button
 * */
void BluetoothGUI::mousePressEvent(QMouseEvent *event){
    // If left button is pressed
    if(event->button() == Qt::LeftButton){
        // If the map is in focus
        if(ui->openGLWidget->hasFocus()){
            dragging_map = true;
            // Start position of the cursor
            cursor_start = event->pos() + translation;

        }
    }
}

/*
 * Handles events produces when any mouse button is released
 * */
void BluetoothGUI::mouseReleaseEvent(QMouseEvent *event){
    // If the left button is released and dragging_map is true
    if (event->button() == Qt::LeftButton && dragging_map) {
        // Calculate new translsation
        translateMap(event->pos());
        dragging_map = false;
    }
}

/*
 * Handles events produces when the mouse is moved
 * */
void BluetoothGUI::mouseMoveEvent(QMouseEvent *event){
    // If leftmouse is pressed and the map is being dragged
    if((event->buttons() & Qt::LeftButton) && dragging_map){
        // Calculate new translation
        translateMap(event->pos());
    }
}

/*****************************************************************
 * Functions regarding the map
 *
 * **************************************************************/

/*
 * Paintevent handler
 * */
void BluetoothGUI::paintEvent(QPaintEvent *event)
{
    brush.setOrigin(ui->openGLWidget->size());

    QPainter painter;
    painter.begin(ui->openGLWidget);
    painter.setRenderHint(QPainter::Antialiasing);

    brush.paint(&painter, event, elapsed, image_scale, translation, draw_position);
    painter.end();
}

/*
 * Translates the map in the openGLwidget
 * */
void BluetoothGUI::translateMap(QPoint mouse_position){
    // Calculate translation from the starting position of the cursor
    QPoint new_translation = (cursor_start - mouse_position);
    qDebug() << "Translation: " << new_translation;
    translation = new_translation;
}

/*
 * Resets translation
 * */
void BluetoothGUI::resetTranslation(){
    qDebug() << "Reset translation";
    translation.setX(0);
    translation.setY(0);
}

/*
 * Resets zoom
 * */
void BluetoothGUI::resetZoom(){
    qDebug() << "Reset zoom";
    image_scale = 1;
    setScaleText();
}

/*
 * When the checkbox "draw position" is checked
 * */
void BluetoothGUI::drawEstimatedPositions(bool checked){
    // Set variable to true
    qDebug() << "Draw position is" << checked;
    draw_position = checked;
}

/*
 * Updates the map when zooming or translating
 * */
void BluetoothGUI::animate()
{
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
    update();
}

/*
 * Indicates how many pixels are equal to 1 meter in the GUI
 * */
void BluetoothGUI::setScaleText(){
    double real_scale = brush.getImageScale()*image_scale;
    QString text = QString::number(real_scale);
    ui->scale->setText(text);
}

/*****************************************************************
 * Functions regarding bluetooth communication
 *
 * **************************************************************/

/*
 * Sends the command typed in the command line to the connected device
 * */
void BluetoothGUI::sendCommand(){
    qDebug() << "Send command";
    QString command = ui->command_line->text();

    if(!command.isEmpty()){
        sendToDevice(command);
        ui->command_line->setText("");
    }
}

/*
 * Sends the string to the connected device
 * */
void BluetoothGUI::sendToDevice(QString &string){
    if(connectedToDevice){
        QList<QLowEnergyCharacteristic> c = service->characteristics();

        string.push_front('[');
        string.push_back(']');

        QByteArray byte_string = string.toLocal8Bit();

        for(int i = 0; i < c.size(); i++){
            service->writeCharacteristic(c.at(i), byte_string,
                                         QLowEnergyService::WriteMode::WriteWithoutResponse);
            qDebug() << "Command: " << string << "sent.";
        }
    }
}

/*
 * Indicates that newValue has been sent to the connected device
 * */
void BluetoothGUI::characteristicWrittenSuccessfully(const QLowEnergyCharacteristic &c,
                                                     const QByteArray &newValue){
    qDebug() << "Write successfull: " << newValue;
}

/*
 * Indicates that value was read successfully from the connected device
 * */
void BluetoothGUI::readSuccessfull(const QLowEnergyCharacteristic &c, const QByteArray &value){
    qDebug() << "Read successfull." << value.toHex().size();
}

/*****************************************************************
 * Functions used to set up bluetooth communication
 *
 * **************************************************************/

/*
 * Initiates a scan of bluetooth devices
 * */
void BluetoothGUI::startScan()
{
    qDebug() << "Start scan ...";
    startDeviceDiscovery();
    qDebug() << "Scanning ...";
}

/*
 *  Search for nearvy devices
 */
void BluetoothGUI::startDeviceDiscovery()
{
    if(connectedToDevice){
        // Disconnect device before searching
        LEcontroller->disconnectFromDevice();
    }

    // Clear list of devices
    ui->devices->clear();

    // Clear list of nearby devices
    nearbyDevices.clear();

    // Create a discovery agent and connect to its signals
    QBluetoothDeviceDiscoveryAgent *discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    discoveryAgent->setLowEnergyDiscoveryTimeout(timeout);

    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &BluetoothGUI::newDeviceDiscovered);

    connect(discoveryAgent, static_cast<void (QBluetoothDeviceDiscoveryAgent::*)(QBluetoothDeviceDiscoveryAgent::Error)>(&QBluetoothDeviceDiscoveryAgent::error),
            this, &BluetoothGUI::scanError);

    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished, this, &BluetoothGUI::scanFinished);
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::canceled, this, &BluetoothGUI::scanFinished);
    // Start a discovery
    discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
    //    discoveryAgent->start();
}

/*
 * When a device is discovered it is added to list of nearby devices
 */
void BluetoothGUI::newDeviceDiscovered(const QBluetoothDeviceInfo &device)
{
    // If LE device
    if(device.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration){
        bool new_device = true;
        // Somehow several detections can be made of the same device.
        // Therefore check to se if a device with the same name is present in the list already.
        if(device.name() == ""){
            // Don't want devices without names
            new_device = false;
        }else{
            for(int i = 0; i < nearbyDevices.size(); i++){
                if(device.name() == nearbyDevices.at(i).name()){
                    new_device = false;
                }
            }
        }


        if(new_device){
            nearbyDevices.append(device);
            qDebug() << "Found new device:" << device.name() << '(' << device.address().toString() << ')';
            qDebug() << "Uuid: " << device.deviceUuid();
        }
    }
}

/*
 * When scan is finished add discovered devices to the drop down list
 * */
void BluetoothGUI::scanFinished(){
    qDebug() << "Scan finished!";
    addDeviceNamesToList();
}

/*
 * Indicates that an error occured when scanning
 * */
void BluetoothGUI::scanError(QBluetoothDeviceDiscoveryAgent::Error error){
    qDebug() << "Error occured while scanning for devices; " << error;
}


/*
 * Adds devives in list nearbyDevices to the list presented in the GUI
 * */
void BluetoothGUI::addDeviceNamesToList()
{
    // Clear list
    ui->devices->clear();

    for(int i = 0; i < nearbyDevices.length(); i++){
        ui->devices->addItem(nearbyDevices.at(i).name());
    }
}

/*
 * Function that attempts to connect to the selected device.
 * */
void BluetoothGUI::connectToDevice()
{
    if(ui->devices->count() > 0){
        int index = ui->devices->currentIndex();
        qDebug() << "Connecting to device: " << nearbyDevices.at(index).name() << " ...";

        // Find address of selected device
        connectedDevice = nearbyDevices.at(index);

        // Create LE controller
        LEcontroller = QLowEnergyController::createCentral(connectedDevice, this);

        connect(LEcontroller, &QLowEnergyController::serviceDiscovered,
                this, &BluetoothGUI::serviceDiscovered);
        connect(LEcontroller, &QLowEnergyController::discoveryFinished,
                this, &BluetoothGUI::serviceScanDone);
        connect(LEcontroller, static_cast<void (QLowEnergyController::*)(QLowEnergyController::Error)>(&QLowEnergyController::error),
                this, [this](QLowEnergyController::Error error) {
            Q_UNUSED(error);
            qDebug() << "Cannot connect to remote device.";
        });
        connect(LEcontroller, &QLowEnergyController::connected, this, [this]() {
            qDebug() << "Controller connected. Search services...";
            LEcontroller->discoverServices();
        });
        connect(LEcontroller, &QLowEnergyController::disconnected, this, [this]() {
            qDebug() << "LowEnergy controller disconnected";
        });

        connect(LEcontroller, SIGNAL(disconnected()), this, SLOT(lostConnection()));
        connect(LEcontroller, SIGNAL(connected()), this, SLOT(newConnection()));

        // Connect
        LEcontroller->connectToDevice();
    }
}

/*
 * When the controller has connected to a device the devices services has to be discovered
 * */
void BluetoothGUI::serviceDiscovered(const QBluetoothUuid &newService){
    qDebug() << "Service discovered with uuid:" << newService.toString();
    service = LEcontroller->createServiceObject(newService);

    if(!service){
        qDebug() << "Cannot create service for uuid";
        return;
    }

    connect(service, &QLowEnergyService::stateChanged, this, &BluetoothGUI::serviceStateChanged);
    service->discoverDetails();

    connect(service, QOverload<QLowEnergyService::ServiceError>::of(&QLowEnergyService::error),
            [=](QLowEnergyService::ServiceError newError){
        qDebug() << "Error occured: " << newError;
    });

    connect(service, SIGNAL(characteristicRead(const QLowEnergyCharacteristic, const QByteArray)),
            this, SLOT(readSuccessfull(const QLowEnergyCharacteristic, const QByteArray)));
    connect(service, SIGNAL(characteristicChanged(const QLowEnergyCharacteristic, const QByteArray)),
            this, SLOT(notification(const QLowEnergyCharacteristic, const QByteArray)));
    connect(service, SIGNAL(characteristicWritten(const QLowEnergyCharacteristic, const QByteArray)),
            this, SLOT(characteristicWrittenSuccessfully(const QLowEnergyCharacteristic, const QByteArray)));
}

/*
 * When discovering services notifications has to be turned on
 * */
void BluetoothGUI::serviceStateChanged(QLowEnergyService::ServiceState s){
    switch (s) {
    case QLowEnergyService::ServiceDiscovered:
    {
        qDebug() << "Service discovered.";

        const QList<QLowEnergyCharacteristic> chars = service->characteristics();
        qDebug() << "Found" << chars.size() << "characteristic(s).";

        for(int i = 0; i < chars.size(); i++){
            qDebug() << "Characteristic uuid:" << chars.at(i).uuid();
            const QList<QLowEnergyDescriptor> desc = chars.at(i).descriptors();

            // Enable notifications
            QLowEnergyDescriptor n = chars.at(i).descriptor(QBluetoothUuid::ClientCharacteristicConfiguration);
            service->writeDescriptor(n, QByteArray::fromHex("0100"));

            for(int j = 0; j < desc.size(); j++){
                qDebug() << j << desc.at(j).name() << desc.at(j).uuid();
            }
        }

        // When a characteristic has been found the connection is done
        if(!connectedToDevice){
            connectedToDevice = true;
            // Notify that a new session has been started
            new_session = true;
            // Send confirmation to the robot
            QString connection_ok("CONN_OK");
            sendToDevice(connection_ok);
        }

        break;
    }
    case QLowEnergyService::DiscoveringServices:
    {
        qDebug() << "Discovering service details.";
        break;
    }
    default:
        break;
    }
}

void BluetoothGUI::serviceError(QLowEnergyService::ServiceError newError){
    qDebug() << "Error occured: " << newError;
}

/*
 * When a notification is received the connected device has sent something new that has to be read.
 * */
void BluetoothGUI::notification(const QLowEnergyCharacteristic &c, const QByteArray &newValue){
    if(connectedToDevice){
        qDebug() << "Notification received";

        QByteArray data = c.value();

        if(save_measurements){
            qDebug() << "Write to file";
            writeToFile(QString("measurements"), data);
        }
        //        QList<QByteArray> values = c.value().split(' ');
        //        for(int i = 0; i < values.size(); i++){
        //            qDebug() << i << ": " << values[i];
        //        }
        // Tell connected device that data was received successfully
        QString data_ok("DATA_OK");
        sendToDevice(data_ok);
    }
}

/*
 * Enable saving of measurements
 * */
void BluetoothGUI::saveMeasurements(bool status){
    qDebug() << "Save measurements is: " << status;
    if(status == true){
        // All previously gathered data should be written over
        new_session = true;
        ekf.resetFilter();
    }

    save_measurements = status;
}


void BluetoothGUI::serviceScanDone(){
    qDebug() << "Service scan done.";
}

/*
 * Disconnect from connected device
 * */
void BluetoothGUI::disconnectDevice(){
    if(connectedToDevice){
        qDebug() << "Disconnecting" << connectedDevice.name();
        // Tell connected device that the user is disconnecting
        QString string("CONN_BREAK");
        sendToDevice(string);
        LEcontroller->disconnectFromDevice();
    }
}

/*
 * When a device has disconnected
 * */
void BluetoothGUI::lostConnection()
{
    qDebug() << "Lost connection to" << connectedDevice.name();
    ui->connected_device->setText("None");
    connectedToDevice = false;
}

/*
 * When a device has connected
 * */
void BluetoothGUI::newConnection()
{
    qDebug() << "New connection to" << connectedDevice.name();
    ui->connected_device->setText(connectedDevice.name());
}

/*****************************************************************
 * Functions regarding kalman filter
 *
 * **************************************************************/

void BluetoothGUI::writeToFile(QString filename, QByteArray &data){
    QFile file;

    // Write to measurements.txt
    if(filename == "measurements"){
        file.setFileName(meas_path);
    }else if(filename == "estimates"){ // Write to output_file.txt
        file.setFileName(path);
    }

    bool file_open;
    // Check if new session
    if(new_session){
        // open file with truncation
        qDebug() << "New session -> truncate";
        file_open = file.open(QIODevice::ReadWrite | QIODevice::Text
                              | QIODevice::Truncate);
        new_session = false;
    }else{
        // Open file with append
        file_open = file.open(QIODevice::ReadWrite | QIODevice::Text
                              | QIODevice::Append);
    }

    // If it failed to open
    if(!file_open){
        qDebug() << "Could not open file";
        return;
    }

    QTextStream out(&file);
    out << data << endl;
    file.close();
}

void BluetoothGUI::runKalmanFilter(){
    if(ekf_enabled){
        ekf.runFilter();
    }
}

void BluetoothGUI::enableEKF(bool status){
    qDebug() << "EKF status is:" << status;
    ekf_enabled = status;
}
