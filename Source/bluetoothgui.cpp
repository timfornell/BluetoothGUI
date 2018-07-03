#include "bluetoothgui.h"
#include "ui_bluetoothgui.h"
#include <QTimer>

BluetoothGUI::BluetoothGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BluetoothGUI)
{
    ui->setupUi(this);

    elapsed = 0;
    ui->openGLWidget->setAutoFillBackground(false);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &BluetoothGUI::animate);
    timer->start(50);
    image_scale = 1;


//    connect(ui->search, SIGNAL (released()), this, SLOT (SearchForDevices()));
//    connect(ui->connect, SIGNAL (released()), this, SLOT (ConnectToDevice()));

    // Check if Bluetooth is available on this device
//    if (localDevice.isValid()) {

//        // Turn Bluetooth on
//        localDevice.powerOn();

//        // Read local device name
//        localDeviceName = localDevice.name();

//        // Make it visible to others
//        localDevice.setHostMode(QBluetoothLocalDevice::HostDiscoverable);

//        // Get connected devices
//        remotes = localDevice.connectedDevices();
//    }
}

BluetoothGUI::~BluetoothGUI()
{
    delete ui;
}

void BluetoothGUI::animate()
{
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
    update();
}

void BluetoothGUI::paintEvent(QPaintEvent *event)
{
    QSize size =  ui->openGLWidget->size();
    int origin_x = size.width()/2;
    int origin_y = size.height()/2;

    QPainter painter;
    painter.begin(ui->openGLWidget);
    painter.setRenderHint(QPainter::Antialiasing);
    brush.paint(&painter, event, elapsed, origin_x, origin_y, image_scale);
    painter.end();
}

void BluetoothGUI::wheelEvent(QWheelEvent *event){
    QPoint numDegrees = event->angleDelta() / 8 / 15;
    int scrolls = numDegrees.y();
    image_scale += 0.01*scrolls;
    qDebug() << "Scale: " << image_scale;
}
// Slots
/*void BluetoothGUI::SearchForDevices()
{
    // Clear list
    ui->devices->clear();

    for(int i = 0; i < 5; i++){
        QString s = "Testing";
        ui->devices->addItem(s);
    }
}

void BluetoothGUI::ConnectToDevice()
{
    int index = ui->devices->currentIndex();
    qDebug("Index: %d", index);
}*/
