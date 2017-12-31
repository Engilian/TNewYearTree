#ifndef T_ABSTRACT_COLOR_H
#define T_ABSTRACT_COLOR_H

#include <QtGlobal>

namespace tui {

typedef  qint32 TRgb;

enum class TColors {

    BLACK	    = 0,
    RED	        = 1,
    GREEN	    = 2,
    YELLOW	    = 3,
    BLUE	    = 4,
    MAGENTA	    = 5,
    CYAN	    = 6,
    WHITE	    = 7
};

///
/// \brief Интерфейс цвета
///
class TAbstractColor
{
public:
    TAbstractColor( TColors c = TColors::BLACK );
    TAbstractColor( TRgb color );
    TAbstractColor( int red, int green, int blue );
    virtual ~TAbstractColor();
public:
    virtual int red() const = 0;
    virtual int green() const = 0;
    virtual int blue() const = 0;
public:
    virtual void setRed( int value ) = 0;
    virtual void setGreen( int value ) = 0;
    virtual void setBlue( int value ) = 0;
public:
    virtual TColors toEnumColor() const = 0;
};

}



#endif // T_ABSTRACT_COLOR_H
