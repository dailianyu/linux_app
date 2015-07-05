/****************************************************************************
** Meta object code from reading C++ file 'qt1.h'
**
** Created: Mon Jan 9 17:50:16 2012
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

static const uint qt_meta_data_MyThread[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_MyThread[] = {
    "MyThread\0\0threadsig(int)\0"
};

const QMetaObject MyThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MyThread,
      qt_meta_data_MyThread, 0 }
};

const QMetaObject *MyThread::metaObject() const
{
    return &staticMetaObject;
}

void *MyThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyThread))
	return static_cast<void*>(const_cast< MyThread*>(this));
    return QThread::qt_metacast(_clname);
}

int MyThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: threadsig((*reinterpret_cast< int(*)>(_a[1]))); break;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void MyThread::threadsig(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_Qt1[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x05,

 // slots: signature, parameters, type, tag, flags
      16,    4,    4,    4, 0x0a,
      33,    4,    4,    4, 0x0a,
      45,    4,    4,    4, 0x0a,
      56,    4,    4,    4, 0x0a,
      67,    4,    4,    4, 0x0a,
      77,    4,    4,    4, 0x0a,
      88,    4,    4,    4, 0x0a,
      97,    4,    4,    4, 0x0a,
     107,    4,    4,    4, 0x0a,
     119,    4,    4,    4, 0x0a,
     130,    4,    4,    4, 0x0a,
     143,    4,    4,    4, 0x0a,
     156,    4,    4,    4, 0x0a,
     168,    4,    4,    4, 0x0a,
     174,    4,    4,    4, 0x0a,
     181,    4,    4,    4, 0x0a,
     191,    4,    4,    4, 0x0a,
     200,    4,    4,    4, 0x0a,
     211,    4,    4,    4, 0x0a,
     221,    4,    4,    4, 0x0a,
     231,    4,    4,    4, 0x0a,
     240,    4,    4,    4, 0x0a,
     251,    4,    4,    4, 0x0a,
     261,    4,    4,    4, 0x0a,
     270,    4,    4,    4, 0x0a,
     280,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Qt1[] = {
    "Qt1\0\0mysig(int)\0mainwinslot(int)\0"
    "myslot(int)\0closefun()\0inputfun()\0"
    "fontfun()\0colorfun()\0te1fun()\0filefun()\0"
    "tstartfun()\0tstopfun()\0timeoutfun()\0"
    "tstartfun2()\0tstopfun2()\0fun()\0fun2()\0"
    "thstart()\0thstop()\0thstart2()\0thstop2()\0"
    "prstart()\0prstop()\0prstart2()\0prstop2()\0"
    "netfun()\0netfun2()\0recvfun()\0"
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
        case 0: mysig((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: mainwinslot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: myslot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: closefun(); break;
        case 4: inputfun(); break;
        case 5: fontfun(); break;
        case 6: colorfun(); break;
        case 7: te1fun(); break;
        case 8: filefun(); break;
        case 9: tstartfun(); break;
        case 10: tstopfun(); break;
        case 11: timeoutfun(); break;
        case 12: tstartfun2(); break;
        case 13: tstopfun2(); break;
        case 14: fun(); break;
        case 15: fun2(); break;
        case 16: thstart(); break;
        case 17: thstop(); break;
        case 18: thstart2(); break;
        case 19: thstop2(); break;
        case 20: prstart(); break;
        case 21: prstop(); break;
        case 22: prstart2(); break;
        case 23: prstop2(); break;
        case 24: netfun(); break;
        case 25: netfun2(); break;
        case 26: recvfun(); break;
        }
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void Qt1::mysig(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
