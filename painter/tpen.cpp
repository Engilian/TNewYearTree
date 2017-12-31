#include "tpen.h"
using namespace tui;

#include "tpen_private.h"

TPen::TPen(const TColor &b, const TColor &c):
    no_public::TObjectPrivate<TAbstractPen> ( new no_public::TPenPrivate( b, c ) )
{

}

TPen::TPen(TColors b, TColors c):
    no_public::TObjectPrivate<TAbstractPen> ( new no_public::TPenPrivate( b, c ) )
{

}

TPen::~TPen()
{

}

TPenStyle TPen::style() const
{
    return _d->style ();
}

void TPen::setStyle(TPenStyle style)
{
    _d->setStyle ( style  );
}

TColor TPen::color() const
{
    return _d->color ();
}

void TPen::setColor(const TColor &color)
{
    _d->setColor ( color );
}

TColor TPen::backgroundColor() const
{
    return _d->backgroundColor ();
}

void TPen::setBackgroundColor(const TColor &color)
{
    _d->setBackgroundColor ( color );
}
