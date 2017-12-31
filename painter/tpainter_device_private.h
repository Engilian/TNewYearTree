#ifndef TPAINTER_DEVICE_PRIVATE_H
#define TPAINTER_DEVICE_PRIVATE_H

#include "tobject_private.h"
#include "tabstract_painter_device.h"

namespace tui {

namespace no_public {

///
/// \brief Устройство вывода
///
class TPainterDevicePrivate: public TAbstractPainterDevice, public TObjectPrivate<TAbstractPainterDevice>
{
    Q_OBJECT
public:
    TPainterDevicePrivate();
    TPainterDevicePrivate( TPainterDevice *parent );
    virtual ~TPainterDevicePrivate();
public:
    void setParent( TPainterDevice *device ) override;
    TPainterDevice *parent() const override;
public:
    QRect rect() const override;
public:
    QPoint pos() const override;
    QPoint centerPos() const override;
public:
    int x() const override;
    int y() const override;
    int cx() const override;
    int cy() const override;
public:
    bool move( const QPoint &p ) override;
    bool move( int x, int y ) override;

    bool moveToCenter( const QPoint &p ) override;
    bool moveToCenter( int x, int y ) override;
public:
    QPoint actualPos() const override;
    QPoint actualCenterPos() const override;
public:
    QSize size() const override;
    int width() const override;
    int height() const override;
public:
    bool resize( int w, int h ) override;
    bool resize( const QSize &size ) override;
public:
    void initKeyHandler() override;
    bool isInitedKeyHandler() const override;
    void destroyKeyHandler() override;
};

}

}



#endif // TPAINTER_DEVICE_PRIVATE_H
