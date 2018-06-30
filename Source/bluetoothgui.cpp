#include "bluetoothgui.h"
#include "ui_bluetoothgui.h"

BluetoothGUI::BluetoothGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BluetoothGUI)
{
    ui->setupUi(this);

    connect(ui->search, SIGNAL (released()), this, SLOT (SearchForDevices()));
    connect(ui->connect, SIGNAL (released()), this, SLOT (ConnectToDevice()));

    // Check if Bluetooth is available on this device
    if (localDevice.isValid()) {

        // Turn Bluetooth on
        localDevice.powerOn();

        // Read local device name
        localDeviceName = localDevice.name();

        // Make it visible to others
        localDevice.setHostMode(QBluetoothLocalDevice::HostDiscoverable);

        // Get connected devices
        remotes = localDevice.connectedDevices();
    }
}

BluetoothGUI::~BluetoothGUI()
{
    delete ui;
}

// Slots
void BluetoothGUI::SearchForDevices()
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
}
