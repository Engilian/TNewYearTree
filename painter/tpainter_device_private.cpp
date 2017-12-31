#include "tpainter_device_private.h"
using namespace tui;
using namespace tui::no_public;

#include "tpainter_private.h"
#include "ncurses_painter_device.h"

TPainterDevicePrivate::TPainterDevicePrivate():
    TObjectPrivate<TAbstractPainterDevice>(
        new NCursesPainterDevice()
        )
{
    connect ( _d.get (),    &TAbstractPainterDevice::resizeEvent,
              this,         &TPainterDevicePrivate::resizeEvent );

    connect ( _d.get (),    &TAbstractPainterDevice::moveEvent,
              this,         &TPainterDevicePrivate::moveEvent );

    connect ( _d.get (),    &TAbstractPainterDevice::keyEvent,
              this,         &TPainterDevicePrivate::keyEvent );

    connect ( _d.get (),    &TAbstractPainterDevice::mouseEvent,
              this,         &TPainterDevicePrivate::mouseEvent );

    connect ( _d.get (),    &TAbstractPainterDevice::updated,
              this,         &TPainterDevicePrivate::updated);
}

TPainterDevicePrivate::TPainterDevicePrivate(TPainterDevice *parent):
    TObjectPrivate<TAbstractPainterDevice>(
          new NCursesPainterDevice( parent )
        )
{
    connect ( _d.get (),    &TAbstractPainterDevice::resizeEvent,
              this,         &TPainterDevicePrivate::resizeEvent );

    connect ( _d.get (),    &TAbstractPainterDevice::moveEvent,
              this,         &TPainterDevicePrivate::moveEvent );

    connect ( _d.get (),    &TAbstractPainterDevice::keyEvent,
              this,         &TPainterDevicePrivate::keyEvent );

    connect ( _d.get (),    &TAbstractPainterDevice::mouseEvent,
              this,         &TPainterDevicePrivate::mouseEvent );

    connect ( _d.get (),    &TAbstractPainterDevice::updated,
              this,         &TPainterDevicePrivate::updated);
}


TPainterDevicePrivate::~TPainterDevicePrivate()
{

}

void TPainterDevicePrivate::setParent(TPainterDevice *device)
{
    _d->setParent ( device );
}

TPainterDevice *TPainterDevicePrivate::parent() const
{
    return _d->parent();
}

QRect TPainterDevicePrivate::rect() const
{
    return _d->rect ();
}

QPoint TPainterDevicePrivate::pos() const
{
    return _d->pos ();
}

QPoint TPainterDevicePrivate::centerPos() const
{
    return _d->centerPos ();
}

int TPainterDevicePrivate::x() const
{
    return _d->x ();
}

int TPainterDevicePrivate::y() const
{
    return _d->y ();
}

int TPainterDevicePrivate::cx() const
{
    return _d->cx ();
}

int TPainterDevicePrivate::cy() const
{
    return _d->cy ();
}

bool TPainterDevicePrivate::move(const QPoint &p)
{
    return _d->move ( p );
}

bool TPainterDevicePrivate::move(int x, int y)
{
    return _d->move ( x, y );
}

bool TPainterDevicePrivate::moveToCenter(const QPoint &p)
{
    return _d->moveToCenter ( p );
}

bool TPainterDevicePrivate::moveToCenter(int x, int y)
{
    return _d->moveToCenter ( x, y );
}

QPoint TPainterDevicePrivate::actualPos() const
{
    return _d->actualPos ();
}

QPoint TPainterDevicePrivate::actualCenterPos() const
{
    return _d->actualCenterPos ();
}

QSize TPainterDevicePrivate::size() const
{
    return _d->size ();
}

int TPainterDevicePrivate::width() const
{
    return _d->width ();
}

int TPainterDevicePrivate::height() const
{
    return _d->height ();
}

bool TPainterDevicePrivate::resize(int w, int h)
{
    return _d->resize ( w, h );
}

bool TPainterDevicePrivate::resize(const QSize &size)
{
    return _d->resize ( size );
}

void TPainterDevicePrivate::initKeyHandler()
{
    _d->initKeyHandler ();
}

bool TPainterDevicePrivate::isInitedKeyHandler() const
{
    return _d->isInitedKeyHandler ();
}

void TPainterDevicePrivate::destroyKeyHandler()
{
    _d->destroyKeyHandler ();
}
