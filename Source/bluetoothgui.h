#ifndef BLUETOOTHGUI_H
#define BLUETOOTHGUI_H

#include <QMainWindow>
#include <QtBluetooth>
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

public slots:
//    void SearchForDevices();
//    void ConnectToDevice();
//    void DrawTrajectory();

private:
    Ui::BluetoothGUI *ui;
    Painter brush;
    int elapsed;
    double image_scale;

    // Host info
//    QBluetoothLocalDevice localDevice;
//    QString localDeviceName;
//    // Nearby devices
//    QList<QBluetoothAddress> nearbyDevices;
//    // Connected devices
//    QList<QBluetoothAddress> remotes;
};

#endif // BLUETOOTHGUI_H
