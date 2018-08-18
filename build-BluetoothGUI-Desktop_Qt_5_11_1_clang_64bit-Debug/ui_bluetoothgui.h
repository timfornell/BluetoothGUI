/********************************************************************************
** Form generated from reading UI file 'bluetoothgui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLUETOOTHGUI_H
#define UI_BLUETOOTHGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BluetoothGUI
{
public:
    QAction *actionReset_translation;
    QAction *actionReset_zoom;
    QWidget *centralWidget;
    QGridLayout *gridLayout_7;
    QGridLayout *Sliders;
    QSlider *slider_3;
    QSlider *slider_2;
    QLabel *label_1;
    QSlider *slider_1;
    QLabel *label_3;
    QLabel *label_2;
    QVBoxLayout *Bluetooth;
    QVBoxLayout *Search_connect;
    QPushButton *search;
    QComboBox *devices;
    QPushButton *connect;
    QPushButton *disconnect;
    QHBoxLayout *Connection;
    QLabel *connected_to;
    QLabel *connected_device;
    QHBoxLayout *horizontalLayout;
    QLineEdit *command_line;
    QPushButton *send_command;
    QGridLayout *Start_stop;
    QPushButton *stop;
    QPushButton *start;
    QGridLayout *Manual_controls;
    QPushButton *D;
    QPushButton *Q;
    QPushButton *A;
    QPushButton *E;
    QPushButton *S;
    QPushButton *W;
    QTextBrowser *console;
    QOpenGLWidget *openGLWidget;
    QGridLayout *Missions;
    QCheckBox *draw_positions;
    QCheckBox *save_meas;
    QCheckBox *checkBox_2;
    QCheckBox *enable_ekf;
    QGridLayout *gridLayout;
    QLineEdit *Q_value;
    QLabel *R;
    QLabel *Q_2;
    QLabel *label_4;
    QLabel *scale;
    QLineEdit *R_value;
    QMenuBar *menuBar;
    QMenu *menuMap;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *BluetoothGUI)
    {
        if (BluetoothGUI->objectName().isEmpty())
            BluetoothGUI->setObjectName(QStringLiteral("BluetoothGUI"));
        BluetoothGUI->resize(987, 785);
        actionReset_translation = new QAction(BluetoothGUI);
        actionReset_translation->setObjectName(QStringLiteral("actionReset_translation"));
        actionReset_zoom = new QAction(BluetoothGUI);
        actionReset_zoom->setObjectName(QStringLiteral("actionReset_zoom"));
        centralWidget = new QWidget(BluetoothGUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_7 = new QGridLayout(centralWidget);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        Sliders = new QGridLayout();
        Sliders->setSpacing(6);
        Sliders->setObjectName(QStringLiteral("Sliders"));
        slider_3 = new QSlider(centralWidget);
        slider_3->setObjectName(QStringLiteral("slider_3"));
        slider_3->setOrientation(Qt::Horizontal);

        Sliders->addWidget(slider_3, 2, 1, 1, 1);

        slider_2 = new QSlider(centralWidget);
        slider_2->setObjectName(QStringLiteral("slider_2"));
        slider_2->setOrientation(Qt::Horizontal);

        Sliders->addWidget(slider_2, 1, 1, 1, 1);

        label_1 = new QLabel(centralWidget);
        label_1->setObjectName(QStringLiteral("label_1"));

        Sliders->addWidget(label_1, 0, 0, 1, 1);

        slider_1 = new QSlider(centralWidget);
        slider_1->setObjectName(QStringLiteral("slider_1"));
        slider_1->setOrientation(Qt::Horizontal);

        Sliders->addWidget(slider_1, 0, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        Sliders->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        Sliders->addWidget(label_2, 1, 0, 1, 1);


        gridLayout_7->addLayout(Sliders, 6, 0, 1, 1);

        Bluetooth = new QVBoxLayout();
        Bluetooth->setSpacing(6);
        Bluetooth->setObjectName(QStringLiteral("Bluetooth"));
        Search_connect = new QVBoxLayout();
        Search_connect->setSpacing(6);
        Search_connect->setObjectName(QStringLiteral("Search_connect"));
        search = new QPushButton(centralWidget);
        search->setObjectName(QStringLiteral("search"));

        Search_connect->addWidget(search);

        devices = new QComboBox(centralWidget);
        devices->setObjectName(QStringLiteral("devices"));

        Search_connect->addWidget(devices);

        connect = new QPushButton(centralWidget);
        connect->setObjectName(QStringLiteral("connect"));

        Search_connect->addWidget(connect);

        disconnect = new QPushButton(centralWidget);
        disconnect->setObjectName(QStringLiteral("disconnect"));

        Search_connect->addWidget(disconnect);


        Bluetooth->addLayout(Search_connect);

        Connection = new QHBoxLayout();
        Connection->setSpacing(6);
        Connection->setObjectName(QStringLiteral("Connection"));
        Connection->setSizeConstraint(QLayout::SetNoConstraint);
        connected_to = new QLabel(centralWidget);
        connected_to->setObjectName(QStringLiteral("connected_to"));

        Connection->addWidget(connected_to);

        connected_device = new QLabel(centralWidget);
        connected_device->setObjectName(QStringLiteral("connected_device"));
        connected_device->setMinimumSize(QSize(191, 39));

        Connection->addWidget(connected_device);


        Bluetooth->addLayout(Connection);


        gridLayout_7->addLayout(Bluetooth, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        command_line = new QLineEdit(centralWidget);
        command_line->setObjectName(QStringLiteral("command_line"));

        horizontalLayout->addWidget(command_line);

        send_command = new QPushButton(centralWidget);
        send_command->setObjectName(QStringLiteral("send_command"));

        horizontalLayout->addWidget(send_command);


        gridLayout_7->addLayout(horizontalLayout, 4, 0, 1, 1);

        Start_stop = new QGridLayout();
        Start_stop->setSpacing(6);
        Start_stop->setObjectName(QStringLiteral("Start_stop"));
        stop = new QPushButton(centralWidget);
        stop->setObjectName(QStringLiteral("stop"));
        stop->setMinimumSize(QSize(81, 61));

        Start_stop->addWidget(stop, 0, 0, 1, 1);

        start = new QPushButton(centralWidget);
        start->setObjectName(QStringLiteral("start"));
        start->setMinimumSize(QSize(81, 61));

        Start_stop->addWidget(start, 0, 1, 1, 1);


        gridLayout_7->addLayout(Start_stop, 9, 0, 1, 1);

        Manual_controls = new QGridLayout();
        Manual_controls->setSpacing(6);
        Manual_controls->setObjectName(QStringLiteral("Manual_controls"));
        Manual_controls->setSizeConstraint(QLayout::SetMaximumSize);
        D = new QPushButton(centralWidget);
        D->setObjectName(QStringLiteral("D"));
        D->setMaximumSize(QSize(51, 51));

        Manual_controls->addWidget(D, 1, 2, 1, 1);

        Q = new QPushButton(centralWidget);
        Q->setObjectName(QStringLiteral("Q"));
        Q->setMaximumSize(QSize(51, 51));

        Manual_controls->addWidget(Q, 0, 0, 1, 1);

        A = new QPushButton(centralWidget);
        A->setObjectName(QStringLiteral("A"));
        A->setMaximumSize(QSize(51, 51));

        Manual_controls->addWidget(A, 1, 0, 1, 1);

        E = new QPushButton(centralWidget);
        E->setObjectName(QStringLiteral("E"));
        E->setMaximumSize(QSize(51, 51));

        Manual_controls->addWidget(E, 0, 2, 1, 1);

        S = new QPushButton(centralWidget);
        S->setObjectName(QStringLiteral("S"));
        S->setMaximumSize(QSize(51, 51));

        Manual_controls->addWidget(S, 1, 1, 1, 1);

        W = new QPushButton(centralWidget);
        W->setObjectName(QStringLiteral("W"));
        W->setMaximumSize(QSize(51, 51));

        Manual_controls->addWidget(W, 0, 1, 1, 1);


        gridLayout_7->addLayout(Manual_controls, 9, 1, 1, 1);

        console = new QTextBrowser(centralWidget);
        console->setObjectName(QStringLiteral("console"));

        gridLayout_7->addWidget(console, 2, 1, 5, 1);

        openGLWidget = new QOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));

        gridLayout_7->addWidget(openGLWidget, 0, 0, 3, 1);

        Missions = new QGridLayout();
        Missions->setSpacing(6);
        Missions->setObjectName(QStringLiteral("Missions"));
        draw_positions = new QCheckBox(centralWidget);
        draw_positions->setObjectName(QStringLiteral("draw_positions"));

        Missions->addWidget(draw_positions, 0, 0, 1, 1);

        save_meas = new QCheckBox(centralWidget);
        save_meas->setObjectName(QStringLiteral("save_meas"));

        Missions->addWidget(save_meas, 1, 0, 1, 1);

        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        Missions->addWidget(checkBox_2, 1, 1, 1, 1);

        enable_ekf = new QCheckBox(centralWidget);
        enable_ekf->setObjectName(QStringLiteral("enable_ekf"));

        Missions->addWidget(enable_ekf, 0, 1, 1, 1);


        gridLayout_7->addLayout(Missions, 5, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Q_value = new QLineEdit(centralWidget);
        Q_value->setObjectName(QStringLiteral("Q_value"));

        gridLayout->addWidget(Q_value, 1, 1, 1, 1);

        R = new QLabel(centralWidget);
        R->setObjectName(QStringLiteral("R"));

        gridLayout->addWidget(R, 2, 0, 1, 1);

        Q_2 = new QLabel(centralWidget);
        Q_2->setObjectName(QStringLiteral("Q_2"));

        gridLayout->addWidget(Q_2, 1, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        scale = new QLabel(centralWidget);
        scale->setObjectName(QStringLiteral("scale"));

        gridLayout->addWidget(scale, 0, 1, 1, 1);

        R_value = new QLineEdit(centralWidget);
        R_value->setObjectName(QStringLiteral("R_value"));

        gridLayout->addWidget(R_value, 2, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout, 0, 1, 2, 1);

        BluetoothGUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BluetoothGUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 987, 22));
        menuMap = new QMenu(menuBar);
        menuMap->setObjectName(QStringLiteral("menuMap"));
        BluetoothGUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BluetoothGUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BluetoothGUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
#ifndef QT_NO_SHORTCUT
        label_1->setBuddy(slider_1);
        label_3->setBuddy(slider_3);
        label_2->setBuddy(slider_2);
#endif // QT_NO_SHORTCUT

        menuBar->addAction(menuMap->menuAction());
        menuMap->addAction(actionReset_translation);
        menuMap->addAction(actionReset_zoom);

        retranslateUi(BluetoothGUI);

        QMetaObject::connectSlotsByName(BluetoothGUI);
    } // setupUi

    void retranslateUi(QMainWindow *BluetoothGUI)
    {
        BluetoothGUI->setWindowTitle(QApplication::translate("BluetoothGUI", "BluetoothGUI", nullptr));
        actionReset_translation->setText(QApplication::translate("BluetoothGUI", "Reset translation", nullptr));
        actionReset_zoom->setText(QApplication::translate("BluetoothGUI", "Reset zoom", nullptr));
        label_1->setText(QApplication::translate("BluetoothGUI", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("BluetoothGUI", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("BluetoothGUI", "TextLabel", nullptr));
        search->setText(QApplication::translate("BluetoothGUI", "Search for device", nullptr));
        connect->setText(QApplication::translate("BluetoothGUI", "Connect", nullptr));
        disconnect->setText(QApplication::translate("BluetoothGUI", "Disconnect", nullptr));
        connected_to->setText(QApplication::translate("BluetoothGUI", "Connected to:", nullptr));
        connected_device->setText(QString());
        send_command->setText(QApplication::translate("BluetoothGUI", "Send", nullptr));
        stop->setText(QApplication::translate("BluetoothGUI", "Stop", nullptr));
        start->setText(QApplication::translate("BluetoothGUI", "Start", nullptr));
        D->setText(QApplication::translate("BluetoothGUI", "D", nullptr));
        Q->setText(QApplication::translate("BluetoothGUI", "Q", nullptr));
        A->setText(QApplication::translate("BluetoothGUI", "A", nullptr));
        E->setText(QApplication::translate("BluetoothGUI", "E", nullptr));
        S->setText(QApplication::translate("BluetoothGUI", "S", nullptr));
        W->setText(QApplication::translate("BluetoothGUI", "W", nullptr));
        draw_positions->setText(QApplication::translate("BluetoothGUI", "Draw position", nullptr));
        save_meas->setText(QApplication::translate("BluetoothGUI", "Save Measurements", nullptr));
        checkBox_2->setText(QApplication::translate("BluetoothGUI", "Mission 4", nullptr));
        enable_ekf->setText(QApplication::translate("BluetoothGUI", "Enable EKF", nullptr));
        R->setText(QApplication::translate("BluetoothGUI", "Observation noise, R:", nullptr));
        Q_2->setText(QApplication::translate("BluetoothGUI", "Process noise, G*Q*G':", nullptr));
        label_4->setText(QApplication::translate("BluetoothGUI", "Scale (1 meter is equal to # pixels):", nullptr));
        scale->setText(QString());
        menuMap->setTitle(QApplication::translate("BluetoothGUI", "Map", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BluetoothGUI: public Ui_BluetoothGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUETOOTHGUI_H
