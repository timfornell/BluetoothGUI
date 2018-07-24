/****************************************************************************
** Meta object code from reading C++ file 'bluetoothgui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Source/bluetoothgui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetoothgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BluetoothGUI_t {
    QByteArrayData data[35];
    char stringdata0[530];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BluetoothGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BluetoothGUI_t qt_meta_stringdata_BluetoothGUI = {
    {
QT_MOC_LITERAL(0, 0, 12), // "BluetoothGUI"
QT_MOC_LITERAL(1, 13, 19), // "newDeviceDiscovered"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(4, 55, 6), // "device"
QT_MOC_LITERAL(5, 62, 9), // "startScan"
QT_MOC_LITERAL(6, 72, 12), // "scanFinished"
QT_MOC_LITERAL(7, 85, 9), // "scanError"
QT_MOC_LITERAL(8, 95, 37), // "QBluetoothDeviceDiscoveryAgen..."
QT_MOC_LITERAL(9, 133, 5), // "error"
QT_MOC_LITERAL(10, 139, 17), // "serviceDiscovered"
QT_MOC_LITERAL(11, 157, 14), // "QBluetoothUuid"
QT_MOC_LITERAL(12, 172, 10), // "newService"
QT_MOC_LITERAL(13, 183, 15), // "serviceScanDone"
QT_MOC_LITERAL(14, 199, 15), // "connectToDevice"
QT_MOC_LITERAL(15, 215, 16), // "disconnectDevice"
QT_MOC_LITERAL(16, 232, 14), // "lostConnection"
QT_MOC_LITERAL(17, 247, 9), // "resetZoom"
QT_MOC_LITERAL(18, 257, 16), // "resetTranslation"
QT_MOC_LITERAL(19, 274, 22), // "drawEstimatedPositions"
QT_MOC_LITERAL(20, 297, 7), // "checked"
QT_MOC_LITERAL(21, 305, 19), // "serviceStateChanged"
QT_MOC_LITERAL(22, 325, 31), // "QLowEnergyService::ServiceState"
QT_MOC_LITERAL(23, 357, 1), // "s"
QT_MOC_LITERAL(24, 359, 15), // "readSuccessfull"
QT_MOC_LITERAL(25, 375, 24), // "QLowEnergyCharacteristic"
QT_MOC_LITERAL(26, 400, 1), // "c"
QT_MOC_LITERAL(27, 402, 5), // "value"
QT_MOC_LITERAL(28, 408, 12), // "notification"
QT_MOC_LITERAL(29, 421, 8), // "newValue"
QT_MOC_LITERAL(30, 430, 11), // "sendCommand"
QT_MOC_LITERAL(31, 442, 33), // "characteristicWrittenSuccessf..."
QT_MOC_LITERAL(32, 476, 12), // "serviceError"
QT_MOC_LITERAL(33, 489, 31), // "QLowEnergyService::ServiceError"
QT_MOC_LITERAL(34, 521, 8) // "newError"

    },
    "BluetoothGUI\0newDeviceDiscovered\0\0"
    "QBluetoothDeviceInfo\0device\0startScan\0"
    "scanFinished\0scanError\0"
    "QBluetoothDeviceDiscoveryAgent::Error\0"
    "error\0serviceDiscovered\0QBluetoothUuid\0"
    "newService\0serviceScanDone\0connectToDevice\0"
    "disconnectDevice\0lostConnection\0"
    "resetZoom\0resetTranslation\0"
    "drawEstimatedPositions\0checked\0"
    "serviceStateChanged\0QLowEnergyService::ServiceState\0"
    "s\0readSuccessfull\0QLowEnergyCharacteristic\0"
    "c\0value\0notification\0newValue\0sendCommand\0"
    "characteristicWrittenSuccessfully\0"
    "serviceError\0QLowEnergyService::ServiceError\0"
    "newError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BluetoothGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x0a /* Public */,
       5,    0,  107,    2, 0x0a /* Public */,
       6,    0,  108,    2, 0x0a /* Public */,
       7,    1,  109,    2, 0x0a /* Public */,
      10,    1,  112,    2, 0x0a /* Public */,
      13,    0,  115,    2, 0x0a /* Public */,
      14,    0,  116,    2, 0x0a /* Public */,
      15,    0,  117,    2, 0x0a /* Public */,
      16,    0,  118,    2, 0x0a /* Public */,
      17,    0,  119,    2, 0x0a /* Public */,
      18,    0,  120,    2, 0x0a /* Public */,
      19,    1,  121,    2, 0x0a /* Public */,
      21,    1,  124,    2, 0x0a /* Public */,
      24,    2,  127,    2, 0x0a /* Public */,
      28,    2,  132,    2, 0x0a /* Public */,
      30,    0,  137,    2, 0x0a /* Public */,
      31,    2,  138,    2, 0x0a /* Public */,
      32,    1,  143,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, 0x80000000 | 25, QMetaType::QByteArray,   26,   27,
    QMetaType::Void, 0x80000000 | 25, QMetaType::QByteArray,   26,   29,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25, QMetaType::QByteArray,   26,   29,
    QMetaType::Void, 0x80000000 | 33,   34,

       0        // eod
};

void BluetoothGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BluetoothGUI *_t = static_cast<BluetoothGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newDeviceDiscovered((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 1: _t->startScan(); break;
        case 2: _t->scanFinished(); break;
        case 3: _t->scanError((*reinterpret_cast< QBluetoothDeviceDiscoveryAgent::Error(*)>(_a[1]))); break;
        case 4: _t->serviceDiscovered((*reinterpret_cast< const QBluetoothUuid(*)>(_a[1]))); break;
        case 5: _t->serviceScanDone(); break;
        case 6: _t->connectToDevice(); break;
        case 7: _t->disconnectDevice(); break;
        case 8: _t->lostConnection(); break;
        case 9: _t->resetZoom(); break;
        case 10: _t->resetTranslation(); break;
        case 11: _t->drawEstimatedPositions((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->serviceStateChanged((*reinterpret_cast< QLowEnergyService::ServiceState(*)>(_a[1]))); break;
        case 13: _t->readSuccessfull((*reinterpret_cast< const QLowEnergyCharacteristic(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 14: _t->notification((*reinterpret_cast< const QLowEnergyCharacteristic(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 15: _t->sendCommand(); break;
        case 16: _t->characteristicWrittenSuccessfully((*reinterpret_cast< const QLowEnergyCharacteristic(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 17: _t->serviceError((*reinterpret_cast< QLowEnergyService::ServiceError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothUuid >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService::ServiceState >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyCharacteristic >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyCharacteristic >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyCharacteristic >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService::ServiceError >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BluetoothGUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BluetoothGUI.data,
      qt_meta_data_BluetoothGUI,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BluetoothGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BluetoothGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BluetoothGUI.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int BluetoothGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
