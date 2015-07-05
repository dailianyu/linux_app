/****************************************************************************
** Meta object code from reading C++ file 'qt1.h'
**
** Created: Thu Jan 5 19:51:04 2012
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt1.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_Qt1[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x0a,
      11,    4,    4,    4, 0x0a,
      18,    4,    4,    4, 0x0a,
      28,    4,    4,    4, 0x0a,
      37,    4,    4,    4, 0x0a,
      48,    4,    4,    4, 0x0a,
      58,    4,    4,    4, 0x0a,
      68,    4,    4,    4, 0x0a,
      77,    4,    4,    4, 0x0a,
      88,    4,    4,    4, 0x0a,
      98,    4,    4,    4, 0x0a,
     107,    4,    4,    4, 0x0a,
     117,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Qt1[] = {
    "Qt1\0\0fun()\0fun2()\0thstart()\0thstop()\0"
    "thstart2()\0thstop2()\0prstart()\0prstop()\0"
    "prstart2()\0prstop2()\0netfun()\0netfun2()\0"
    "recvfun()\0"
};

const QMetaObject Qt1::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Qt1,
      qt_meta_data_Qt1, 0 }
};

const QMetaObject *Qt1::metaObject() const
{
    return &staticMetaObject;
}

void *Qt1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Qt1))
	return static_cast<void*>(const_cast< Qt1*>(this));
    if (!strcmp(_clname, "Ui_Qt1"))
	return static_cast< Ui_Qt1*>(const_cast< Qt1*>(this));
    return QDialog::qt_metacast(_clname);
}

int Qt1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: fun(); break;
        case 1: fun2(); break;
        case 2: thstart(); break;
        case 3: thstop(); break;
        case 4: thstart2(); break;
        case 5: thstop2(); break;
        case 6: prstart(); break;
        case 7: prstop(); break;
        case 8: prstart2(); break;
        case 9: prstop2(); break;
        case 10: netfun(); break;
        case 11: netfun2(); break;
        case 12: recvfun(); break;
        }
        _id -= 13;
    }
    return _id;
}
