#ifndef NCURSES_PAINTER_DEVICE_H
#define NCURSES_PAINTER_DEVICE_H

#include "tcolor.h"
#include "tpainter_device.h"
#include <ncurses.h>

class NCursesPainterDevice: public tui::TAbstractPainterDevice
{
    Q_OBJECT
public:
    NCursesPainterDevice( tui::TPainterDevice *parent = nullptr );
    ~NCursesPainterDevice();
protected:
    void timerEvent(QTimerEvent *event) override;
public:
    void setParent( tui::TPainterDevice *device ) override;
    tui::TPainterDevice *parent() const override;
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
protected:
    void createWindow();
    void removeWindow();
public:
    void initKeyHandler() override;
    bool isInitedKeyHandler() const override;
    void destroyKeyHandler() override;
private:
    void _keyHandlerWork();
private:
    QPoint  _pos;
    QPoint  _actualPos;
    int     _w;
    int     _h;

    tui::TPainterDevice *_parent;
private:
    ///
    /// \brief Статус отловщика
    ///
    std::pair<bool, bool>   _keyHandlerStatus;

public:
    WINDOW  *_window;


public slots:
    void parentMoved( tui::TMoveEvent * );
    void parentUpdated();
};

#endif // NCURSES_PAINTER_DEVICE_H
