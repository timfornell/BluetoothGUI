#ifndef BLUETOOTHGUI_H
#define BLUETOOTHGUI_H

#include <QMainWindow>
#include <QtBluetooth>
#include <QBluetoothLocalDevice>
#include "painter.h"
//#include <QList>
//#include <QString>

namespace Ui {
class BluetoothGUI;
}

class BluetoothGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit BluetoothGUI(QWidget *parent = 0);
    ~BluetoothGUI();
    void animate();
    void paintEvent(QPaintEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void startDeviceDiscovery();
    void addDevicesToList();


public slots:
//    void SearchForDevices();

//    void DrawTrajectory();
    void sendTestMessage(const QString &message);
    void deviceDiscovered(const QBluetoothDeviceInfo &device);
    void startScan();
    void ConnectToDevice();
    void pairingDone(const QBluetoothAddress &address,QBluetoothLocalDevice::Pairing pairing);
    void lostConnection(const QBluetoothAddress &address);
    void newConnection(const QBluetoothAddress &address);

private:
    Ui::BluetoothGUI *ui;
    Painter brush;
    int elapsed;
    double image_scale;

    // Host info
    QBluetoothLocalDevice *localDevice;
    QString localDeviceName;
    // Nearby devices
    QList<QBluetoothDeviceInfo> nearbyDevices;
    QBluetoothDeviceInfo connectedDevice;
    QBluetoothAddress connectedDeviceAddress;
//    QList<QBluetoothAddress> nearbyDevices;
//    // Connected devices
//    QList<QBluetoothAddress> remotes;
};

#endif // BLUETOOTHGUI_H
