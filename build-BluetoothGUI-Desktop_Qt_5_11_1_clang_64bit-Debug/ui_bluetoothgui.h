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
    QGridLayout *Start_stop;
    QPushButton *stop;
    QPushButton *start;
    QGridLayout *Missions;
    QCheckBox *mission_1;
    QCheckBox *mission_3;
    QCheckBox *mission_4;
    QCheckBox *mission_2;
    QGridLayout *Manual_controls;
    QPushButton *D;
    QPushButton *Q;
    QPushButton *A;
    QPushButton *E;
    QPushButton *S;
    QPushButton *W;
    QTextBrowser *console;
    QHBoxLayout *informationWidget;
    QLabel *label_4;
    QLabel *scale;
    QOpenGLWidget *openGLWidget;
    QVBoxLayout *Bluetooth;
    QVBoxLayout *Search_connect;
    QPushButton *search;
    QComboBox *devices;
    QPushButton *connect;
    QPushButton *disconnect;
    QHBoxLayout *Connection;
    QLabel *connected_to;
    QLabel *connected_device;
    QGridLayout *Sliders;
    QSlider *slider_3;
    QSlider *slider_2;
    QLabel *label_1;
    QSlider *slider_1;
    QLabel *label_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *command_line;
    QPushButton *send_command;
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


        gridLayout_7->addLayout(Start_stop, 8, 0, 1, 1);

        Missions = new QGridLayout();
        Missions->setSpacing(6);
        Missions->setObjectName(QStringLiteral("Missions"));
        mission_1 = new QCheckBox(centralWidget);
        mission_1->setObjectName(QStringLiteral("mission_1"));

        Missions->addWidget(mission_1, 0, 0, 1, 1);

        mission_3 = new QCheckBox(centralWidget);
        mission_3->setObjectName(QStringLiteral("mission_3"));

        Missions->addWidget(mission_3, 1, 0, 1, 1);

        mission_4 = new QCheckBox(centralWidget);
        mission_4->setObjectName(QStringLiteral("mission_4"));

        Missions->addWidget(mission_4, 1, 1, 1, 1);

        mission_2 = new QCheckBox(centralWidget);
        mission_2->setObjectName(QStringLiteral("mission_2"));

        Missions->addWidget(mission_2, 0, 1, 1, 1);


        gridLayout_7->addLayout(Missions, 4, 0, 1, 1);

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


        gridLayout_7->addLayout(Manual_controls, 8, 1, 1, 1);

        console = new QTextBrowser(centralWidget);
        console->setObjectName(QStringLiteral("console"));

        gridLayout_7->addWidget(console, 1, 1, 5, 1);

        informationWidget = new QHBoxLayout();
        informationWidget->setSpacing(6);
        informationWidget->setObjectName(QStringLiteral("informationWidget"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        informationWidget->addWidget(label_4);

        scale = new QLabel(centralWidget);
        scale->setObjectName(QStringLiteral("scale"));

        informationWidget->addWidget(scale);


        gridLayout_7->addLayout(informationWidget, 0, 1, 1, 1);

        openGLWidget = new QOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));

        gridLayout_7->addWidget(openGLWidget, 0, 0, 2, 1);

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


        gridLayout_7->addLayout(Bluetooth, 2, 0, 1, 1);

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


        gridLayout_7->addLayout(Sliders, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        command_line = new QLineEdit(centralWidget);
        command_line->setObjectName(QStringLiteral("command_line"));

        horizontalLayout->addWidget(command_line);

        send_command = new QPushButton(centralWidget);
        send_command->setObjectName(QStringLiteral("send_command"));

        horizontalLayout->addWidget(send_command);


        gridLayout_7->addLayout(horizontalLayout, 3, 0, 1, 1);

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
        stop->setText(QApplication::translate("BluetoothGUI", "Stop", nullptr));
        start->setText(QApplication::translate("BluetoothGUI", "Start", nullptr));
        mission_1->setText(QApplication::translate("BluetoothGUI", "Draw position", nullptr));
        mission_3->setText(QApplication::translate("BluetoothGUI", "Mission 3", nullptr));
        mission_4->setText(QApplication::translate("BluetoothGUI", "Mission 4", nullptr));
        mission_2->setText(QApplication::translate("BluetoothGUI", "Mission 2", nullptr));
        D->setText(QApplication::translate("BluetoothGUI", "D", nullptr));
        Q->setText(QApplication::translate("BluetoothGUI", "Q", nullptr));
        A->setText(QApplication::translate("BluetoothGUI", "A", nullptr));
        E->setText(QApplication::translate("BluetoothGUI", "E", nullptr));
        S->setText(QApplication::translate("BluetoothGUI", "S", nullptr));
        W->setText(QApplication::translate("BluetoothGUI", "W", nullptr));
        label_4->setText(QApplication::translate("BluetoothGUI", "Scale (1 meter is equal to # pixels):", nullptr));
        scale->setText(QString());
        search->setText(QApplication::translate("BluetoothGUI", "Search for device", nullptr));
        connect->setText(QApplication::translate("BluetoothGUI", "Connect", nullptr));
        disconnect->setText(QApplication::translate("BluetoothGUI", "Disconnect", nullptr));
        connected_to->setText(QApplication::translate("BluetoothGUI", "Connected to:", nullptr));
        connected_device->setText(QString());
        label_1->setText(QApplication::translate("BluetoothGUI", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("BluetoothGUI", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("BluetoothGUI", "TextLabel", nullptr));
        send_command->setText(QApplication::translate("BluetoothGUI", "Send", nullptr));
        menuMap->setTitle(QApplication::translate("BluetoothGUI", "Map", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BluetoothGUI: public Ui_BluetoothGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUETOOTHGUI_H
