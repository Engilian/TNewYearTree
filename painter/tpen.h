#ifndef TPEN_H
#define TPEN_H

#include "tabstract_pen.h"
#include "tobject_private.h"

namespace tui {

///
/// \brief Карандаш
///
class TPen : public TAbstractPen, public no_public::TObjectPrivate<TAbstractPen>
{
public:
    TPen( const TColor &b = TColor( TColors::WHITE ), const TColor &c = TColor( TColors::BLACK ) );
    TPen( TColors b, TColors c );
    ~TPen();
public:
    TPenStyle style() const override;
    void setStyle( TPenStyle style ) override;
public:
    TColor color() const override;
    void setColor(const TColor &color) override;
public:
    TColor backgroundColor() const override;
    void setBackgroundColor(const TColor &color) override;

};


}


#endif // TPEN_H
