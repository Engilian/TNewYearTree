#ifndef TABSTRACT_PEN_H
#define TABSTRACT_PEN_H

#include "painter/tcolor.h"

namespace tui {

///
/// \brief Стиль рисования карандаша
///
enum class TPenStyle: qint16 {
    NoPen,
    SolidLine,
    DashLine,
    DotLine,
    DashDotLine,
    DashDotDotLine,
};

///
/// \brief Абстрактный карандаш
///
class TAbstractPen
{
protected:
    TAbstractPen();
public:
    virtual ~TAbstractPen();
public:
    virtual TPenStyle style() const = 0;
    virtual void setStyle( TPenStyle style ) = 0;
public:
    virtual TColor color() const = 0;
    virtual void setColor(const TColor &color) = 0;
public:
    virtual TColor backgroundColor() const = 0;
    virtual void setBackgroundColor(const TColor &color) = 0;
};

}



#endif // TABSTRACT_PEN_H
