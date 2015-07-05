/****************************************************************************
** Meta object code from reading C++ file 'qt2.h'
**
** Created: Wed Jan 4 19:53:27 2012
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_Qt2[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Qt2[] = {
    "Qt2\0\0sendmessage(QString)\0"
};

const QMetaObject Qt2::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Qt2,
      qt_meta_data_Qt2, 0 }
};

const QMetaObject *Qt2::metaObject() const
{
    return &staticMetaObject;
}

void *Qt2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Qt2))
	return static_cast<void*>(const_cast< Qt2*>(this));
    if (!strcmp(_clname, "Ui_Qt2"))
	return static_cast< Ui_Qt2*>(const_cast< Qt2*>(this));
    return QDialog::qt_metacast(_clname);
}

int Qt2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendmessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        }
        _id -= 1;
    }
    return _id;
}
