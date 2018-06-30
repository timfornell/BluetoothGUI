#ifndef BLUETOOTHGUI_H
#define BLUETOOTHGUI_H

#include <QMainWindow>

namespace Ui {
class BluetoothGUI;
}

class BluetoothGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit BluetoothGUI(QWidget *parent = 0);
    ~BluetoothGUI();

    // Member functions


private:
    Ui::BluetoothGUI *ui;
};

#endif // BLUETOOTHGUI_H
