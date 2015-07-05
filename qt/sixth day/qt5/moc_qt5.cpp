/****************************************************************************
** Meta object code from reading C++ file 'qt5.h'
**
** Created: Mon Jan 9 19:10:45 2012
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt5.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt5.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_Menu[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x0a,
      11,    5,    5,    5, 0x0a,
      16,    5,    5,    5, 0x0a,
      21,    5,    5,    5, 0x0a,
      28,   26,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Menu[] = {
    "Menu\0\0f1()\0f2()\0f3()\0f4()\0s\0f5(QString)\0"
};

const QMetaObject Menu::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Menu,
      qt_meta_data_Menu, 0 }
};

const QMetaObject *Menu::metaObject() const
{
    return &staticMetaObject;
}

void *Menu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Menu))
	return static_cast<void*>(const_cast< Menu*>(this));
    if (!strcmp(_clname, "Ui_Qt5"))
	return static_cast< Ui_Qt5*>(const_cast< Menu*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: f1(); break;
        case 1: f2(); break;
        case 2: f3(); break;
        case 3: f4(); break;
        case 4: f5((*reinterpret_cast< QString(*)>(_a[1]))); break;
        }
        _id -= 5;
    }
    return _id;
}
