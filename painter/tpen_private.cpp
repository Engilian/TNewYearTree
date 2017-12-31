#include "tpen_private.h"

using namespace tui;
using namespace tui::no_public;

TPenPrivate::TPenPrivate(const TColor &b, const TColor &c):
    TAbstractPen(),
    _style      ( TPenStyle::SolidLine ),
    _color      ( c ),
    _background ( b )
{

}

TPenPrivate::TPenPrivate(TColors b, TColors c):
    TAbstractPen(),
    _style      ( TPenStyle::SolidLine ),
    _color      ( c ),
    _background ( b )
{

}

TPenPrivate::~TPenPrivate()
{

}

TPenStyle TPenPrivate::style() const
{
    return _style;
}

void TPenPrivate::setStyle(TPenStyle style)
{
    _style = style;
}

TColor TPenPrivate::color() const
{
    return _color;
}

void TPenPrivate::setColor(const TColor &color)
{
    _color = color;
}

TColor TPenPrivate::backgroundColor() const
{
    return _background;
}

void TPenPrivate::setBackgroundColor(const TColor &color)
{
    _background = color;
}
