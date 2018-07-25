#ifndef BLUETOOTHGUI_H
#define BLUETOOTHGUI_H

#include <QMainWindow>
#include <QtBluetooth>
#include <QBluetoothLocalDevice>
#include <QFile>
//#include <QKeyEvent>
//#include <QWidget>

#include "painter.h"


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
    void addDeviceNamesToList();
    void setScaleText();
    void sendToDevice(QString &string);
    void removePressedButton(int key);

    // Override functions
    void paintEvent(QPaintEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

public slots:
    void newDeviceDiscovered(const QBluetoothDeviceInfo &device);
    void startScan();
    void scanFinished();
    void scanError(QBluetoothDeviceDiscoveryAgent::Error error);
    void serviceDiscovered(const QBluetoothUuid &newService);
    void serviceScanDone();
    void connectToDevice();
    void disconnectDevice();
    void lostConnection();
    void newConnection();
    void resetZoom();
    void resetTranslation();
    void drawEstimatedPositions(bool checked);
    void serviceStateChanged(QLowEnergyService::ServiceState s);
    void readSuccessfull(const QLowEnergyCharacteristic &c, const QByteArray &value);
    void notification(const QLowEnergyCharacteristic &c, const QByteArray &newValue);
    void sendCommand();
    void characteristicWrittenSuccessfully(const QLowEnergyCharacteristic &c,
                                           const QByteArray &newValue);
    void serviceError(QLowEnergyService::ServiceError newError);

private:
    Ui::BluetoothGUI *ui;

    // Variables for the openGLwidget
    Painter brush;
    int elapsed;
    double image_scale;
    bool dragging_map;
    QPoint cursor_start;
    QPoint translation;
    bool draw_position;
    int timeout;

    QString path;

    // Host info
    QBluetoothLocalDevice *localDevice;
    QString localDeviceName;
    // Nearby devices
    QList<QBluetoothDeviceInfo> nearbyDevices;
    QBluetoothDeviceInfo connectedDevice;
    QBluetoothAddress connectedDeviceAddress;

    QLowEnergyController *LEcontroller;
    QLowEnergyService *service;
    QBluetoothSocket *socket;
    bool connectedToDevice;

    QString robot_direction;
    QList<Qt::Key> buttons_pressed;

    //    QList<QBluetoothAddress> nearbyDevices;
    //    // Connected devices
    //    QList<QBluetoothAddress> remotes;
};

#endif // BLUETOOTHGUI_H
