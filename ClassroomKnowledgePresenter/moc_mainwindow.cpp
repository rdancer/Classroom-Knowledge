/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed May 26 04:39:42 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   12,   11,   11, 0x08,
      72,   11,   11,   11, 0x08,
      98,   11,   11,   11, 0x08,
     135,   11,   11,   11, 0x08,
     172,   11,   11,   11, 0x08,
     209,  201,   11,   11, 0x08,
     243,   11,   11,   11, 0x08,
     275,   11,   11,   11, 0x08,
     309,  303,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0item,column\0"
    "on_treeWidget_itemClicked(QTreeWidgetItem*,int)\0"
    "on_actionQuit_triggered()\0"
    "on_question3Answer_editingFinished()\0"
    "on_question2Answer_editingFinished()\0"
    "on_spinBox_editingFinished()\0checked\0"
    "on_question1Answer1_toggled(bool)\0"
    "on_visualPanePrevious_clicked()\0"
    "on_visualPaneNext_clicked()\0index\0"
    "on_tabWidget_currentChanged(int)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_treeWidget_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: on_actionQuit_triggered(); break;
        case 2: on_question3Answer_editingFinished(); break;
        case 3: on_question2Answer_editingFinished(); break;
        case 4: on_spinBox_editingFinished(); break;
        case 5: on_question1Answer1_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: on_visualPanePrevious_clicked(); break;
        case 7: on_visualPaneNext_clicked(); break;
        case 8: on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
