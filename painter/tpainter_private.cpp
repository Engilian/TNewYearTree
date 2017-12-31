#include "tpainter_private.h"
using namespace tui;
using namespace tui::no_public;

#include "tpainter_device.h"
#include "ncurses_painter.h"

TPainterDevice *getPainterDevice( TPainterDevice *device ) {

    return device ? device : new TPainterDevice();
}

TPainterPrivate::TPainterPrivate(TPainterDevice *device):
    TAbstractPainter( nullptr ),
    TObjectPrivate<TAbstractPainter>(
       new NCursesPainter( device ) )
{

}

TPainterPrivate::TPainterPrivate(const TPainterPrivate &p):
    TAbstractPainter( p ),
    TObjectPrivate<TAbstractPainter>( p )
{

}
TPainterPrivate::~TPainterPrivate()
{

}

TColor TPainterPrivate::backgroundColor() const
{
    return _d->backgroundColor ();
}

void TPainterPrivate::setBackgroundColor(const TColor &c)
{
    _d->setBackgroundColor ( c );
}

void TPainterPrivate::setBackgroundColor(TColors c)
{
    _d->setBackgroundColor ( c );
}

void TPainterPrivate::drawPoint(int x, int y, char16_t symbol)
{
    _d->drawPoint( x, y, symbol );
}

void TPainterPrivate::drawPoint(const QPoint &p, char16_t symbol)
{
    _d->drawPoint( p, symbol );
}

void TPainterPrivate::drawLine(int x1, int y1, int x2, int y2, char16_t start, char16_t mid, char16_t end)
{
    _d->drawLine( x1, y1, x2, y2, start, mid, end );
}

void TPainterPrivate::drawLine(int x1, int y1, int x2, int y2, const QString &symbols)
{
    _d->drawLine( x1, y1, x2, y2, symbols );
}

void TPainterPrivate::drawLine(const QPoint &p1, const QPoint &p2, char16_t start, char16_t mid, char16_t end)
{
    _d->drawLine( p1, p2, start, mid, end );
}

void TPainterPrivate::drawLine(const QPoint &p1, const QPoint &p2, const QString &symbols)
{
    _d->drawLine( p1, p2, symbols );
}

void TPainterPrivate::drawLine(const QLine &line, char16_t start, char16_t mid, char16_t end)
{
    _d->drawLine( line, start, mid, end );
}

void TPainterPrivate::drawLine(const QLine &line, const QString &symbols)
{
    _d->drawLine( line, symbols );
}

void TPainterPrivate::drawRect(int x, int y, int w, int h, char16_t tl, char16_t tc, char16_t tr, char16_t cl, char16_t cr, char16_t bl, char16_t bc, char16_t br)
{
    _d->drawRect( x, y, w, h,
              tl, tc, tr,
              cl, cr,
              bl, bc, br );
}

void TPainterPrivate::drawRect(int x, int y, int w, int h, const QString &symbols)
{
    _d->drawRect( x, y, w, h, symbols );
}

void TPainterPrivate::drawRect(const QRect &rect, char16_t tl, char16_t tc, char16_t tr, char16_t cl, char16_t cr, char16_t bl, char16_t bc, char16_t br)
{
    _d->drawRect( rect,
                  tl, tc, tr,
                  cl, cr,
                  bl, bc, br );
}

void TPainterPrivate::drawRect(const QRect &rect, const QString &symbols)
{
    _d->drawRect( rect, symbols );
}



void TPainterPrivate::fillRect(int x, int y, int w, int h, const TColor &color)
{
    _d->fillRect ( x, y, w, h, color );
}

void TPainterPrivate::fillRect(const QRect &r, const TColor &color)
{
    _d->fillRect ( r, color );
}

void TPainterPrivate::fillRect(int x, int y, int w, int h, TRgb c)
{
    _d->fillRect ( x, y, w, h, c );
}

void TPainterPrivate::fillRect(const QRect &r, TRgb c)
{
    _d->fillRect ( r, c );
}


void TPainterPrivate::drawText(QRect &r, QString &text)
{
    _d->drawText ( r, text );
}

void TPainterPrivate::drawText(QPoint p0, int w, int h, QString &text)
{
    _d->drawText ( p0, w, h, text );
}

TPen &TPainterPrivate::pen()
{
    return _d->pen ();
}

void TPainterPrivate::setPen(const TPen &pen)
{
    _d->setPen ( pen );
}

//void TPainterPrivate::setPen(TPen pen)
//{
//    _d->setPen ( pen );
//}

void TPainterPrivate::clearAll()
{
    _d->clearAll ();
}

void TPainterPrivate::flush()
{
    _d->flush ();
}

TPainterDevice *TPainterPrivate::device() const
{
    return _d->device ();
}

void TPainterPrivate::setDevice(TPainterDevice *device)
{
    _d->setDevice ( device );
}
