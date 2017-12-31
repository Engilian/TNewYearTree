#ifndef TPEN_PRIVATE_H
#define TPEN_PRIVATE_H

#include "tabstract_pen.h"

namespace tui {

namespace no_public {

class TPenPrivate: public TAbstractPen
{
public:
    TPenPrivate( const TColor &b = TColor( TColors::WHITE ),
                 const TColor &c = TColor( TColors::BLACK ) );
    TPenPrivate( TColors b, TColors c );
    ~TPenPrivate();
public:
    TPenStyle style() const override;
    void setStyle( TPenStyle style ) override;
public:
    TColor color() const override;
    void setColor(const TColor &color) override;
public:
    TColor backgroundColor() const override;
    void setBackgroundColor(const TColor &color) override;
private:
    TPenStyle   _style;
    TColor      _color;
    TColor      _background;

};

}

}



#endif // TPEN_PRIVATE_H
