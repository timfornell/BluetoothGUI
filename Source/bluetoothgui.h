#ifndef BLUETOOTHGUI_H
#define BLUETOOTHGUI_H

#include <QMainWindow>
#include <QtBluetooth>

namespace Ui {
class BluetoothGUI;
}

class BluetoothGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit BluetoothGUI(QWidget *parent = 0);
    ~BluetoothGUI();

public slots:
    void SearchForDevices();
    void ConnectToDevice();

private:
    Ui::BluetoothGUI *ui;
    // Host info
    QBluetoothLocalDevice localDevice;
    Qstring localDevice;
    // Nearby devices
    Qlist<QBluetoothAddress> nearbyDevices;
    // Connected devices
    Qlist<QBluetoothAddress> remotes;
};

#endif // BLUETOOTHGUI_H
