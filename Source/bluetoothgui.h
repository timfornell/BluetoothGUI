#ifndef BLUETOOTHGUI_H
#define BLUETOOTHGUI_H

#include <QMainWindow>
#include <QtBluetooth>
#include <QBluetoothLocalDevice>
#include <QFile>

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
    ~BluetoothGUI() override;

    // Functions regarding the map
    void animate();
    void translateMap(QPoint pos);

    void startDeviceDiscovery();
    void addDevicesToList();

    // Override functions
    void paintEvent(QPaintEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

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
    void resetZoom();
    void resetTranslation();
    void drawEstimatedPositions(bool checked);

private:
    Ui::BluetoothGUI *ui;

    int elapsed;

    // Variables for the openGLwidget
    Painter brush;
    double image_scale;
    bool dragging_map;
    QPoint cursor_start;
    QPoint translation;
    bool draw_position;

    QString path;

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
