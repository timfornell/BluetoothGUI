#include "bluetoothgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BluetoothGUI w;
    w.runKalmanFilter();

    w.show();

    return a.exec();
}
