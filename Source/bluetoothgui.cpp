#include "bluetoothgui.h"
#include "ui_bluetoothgui.h"

BluetoothGUI::BluetoothGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BluetoothGUI)
{
    ui->setupUi(this);
}

BluetoothGUI::~BluetoothGUI()
{
    delete ui;
}
