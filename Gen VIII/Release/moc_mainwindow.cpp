/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[312];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 22), // "on_kantoButton_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 22), // "on_johtoButton_clicked"
QT_MOC_LITERAL(4, 58, 22), // "on_hoennButton_clicked"
QT_MOC_LITERAL(5, 81, 23), // "on_sinnohButton_clicked"
QT_MOC_LITERAL(6, 105, 22), // "on_unovaButton_clicked"
QT_MOC_LITERAL(7, 128, 22), // "on_kalosButton_clicked"
QT_MOC_LITERAL(8, 151, 22), // "on_alolaButton_clicked"
QT_MOC_LITERAL(9, 174, 22), // "on_galarButton_clicked"
QT_MOC_LITERAL(10, 197, 25), // "on_actionSearch_triggered"
QT_MOC_LITERAL(11, 223, 11), // "CatchSignal"
QT_MOC_LITERAL(12, 235, 14), // "POKEMON_NUMBER"
QT_MOC_LITERAL(13, 250, 29), // "on_actionType_Chart_triggered"
QT_MOC_LITERAL(14, 280, 31) // "on_actionNature_Chart_triggered"

    },
    "MainWindow\0on_kantoButton_clicked\0\0"
    "on_johtoButton_clicked\0on_hoennButton_clicked\0"
    "on_sinnohButton_clicked\0on_unovaButton_clicked\0"
    "on_kalosButton_clicked\0on_alolaButton_clicked\0"
    "on_galarButton_clicked\0on_actionSearch_triggered\0"
    "CatchSignal\0POKEMON_NUMBER\0"
    "on_actionType_Chart_triggered\0"
    "on_actionNature_Chart_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    1,   83,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_kantoButton_clicked(); break;
        case 1: _t->on_johtoButton_clicked(); break;
        case 2: _t->on_hoennButton_clicked(); break;
        case 3: _t->on_sinnohButton_clicked(); break;
        case 4: _t->on_unovaButton_clicked(); break;
        case 5: _t->on_kalosButton_clicked(); break;
        case 6: _t->on_alolaButton_clicked(); break;
        case 7: _t->on_galarButton_clicked(); break;
        case 8: _t->on_actionSearch_triggered(); break;
        case 9: _t->CatchSignal((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 10: _t->on_actionType_Chart_triggered(); break;
        case 11: _t->on_actionNature_Chart_triggered(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
