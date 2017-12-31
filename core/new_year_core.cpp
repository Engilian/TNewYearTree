#include "new_year_core.h"
#include <ncurses.h>
#include <cmath>

using namespace tui;

NewYearCore::NewYearCore(QObject *parent) :
    QObject(parent),
    _device ( new TPainterDevice() ),
    _painter( new TPainter( _device ) ),

    _tree   ( new NewYearTree() ),
    _snow   ( new Snow() )
{
    connect( _device,   &TPainterDevice::resizeEvent,
             this,      &NewYearCore::resizeEvent );

    initscr ();
    start_color ();
    noecho ();

    _painter->setBackgroundColor( TColors::BLACK );
    _painter->flush();

    rebuild();
}

NewYearCore::~NewYearCore()
{
    delete _tree;
    delete _snow;

    delete _painter;
    delete _device;
}

void NewYearCore::timerEvent(QTimerEvent *e)
{
    Q_UNUSED( e );

    repaint();
}

void NewYearCore::rebuild()
{
    int w = _device->width();
    int h = _device->height();

    int tw = w / 2;

    int th = h / 1.5;

//    for ( int i = th; i < tw; i += 2, ++th ) {}
//    th = std::min ( th, h - 3 - 2 );

    QRect r( w - tw - 1, h - th - 2, tw, th );
    _tree->setRect( r );

    r = QRect( 0, 0, _device->width(), _device->height() );
    _snow->setRect( r );
}

void NewYearCore::repaint()
{
    paint();
    flush();
}

void NewYearCore::paint()
{
    noecho ();
    _painter->clearAll();


    _snow->paint( _painter );

    QRect ear( 0, _device->rect().bottomLeft().y() - 2, _device->width(), 2 );
    _painter->fillRect( ear, TColors::WHITE );

    _tree->paint( _painter );


    TPen pen ( TColors::BLACK, TColors::BLACK );
    _painter->setPen( pen );;

    _painter->drawPoint( 0, 0, ' ' );
}

void NewYearCore::flush()
{
    _painter->flush();
}

void NewYearCore::resizeEvent(TResizeEvent *event)
{
    rebuild();
}

