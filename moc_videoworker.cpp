/****************************************************************************
** Meta object code from reading C++ file 'videoworker.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "videoworker.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videoworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN11videoWorkerE_t {};
} // unnamed namespace

template <> constexpr inline auto videoWorker::qt_create_metaobjectdata<qt_meta_tag_ZN11videoWorkerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "videoWorker",
        "run",
        "",
        "pause",
        "resume",
        "stop",
        "togglePause"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'run'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'pause'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'resume'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stop'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'togglePause'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<videoWorker, qt_meta_tag_ZN11videoWorkerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject videoWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11videoWorkerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11videoWorkerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11videoWorkerE_t>.metaTypes,
    nullptr
} };

void videoWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<videoWorker *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->run(); break;
        case 1: _t->pause(); break;
        case 2: _t->resume(); break;
        case 3: _t->stop(); break;
        case 4: _t->togglePause(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *videoWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *videoWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11videoWorkerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int videoWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
