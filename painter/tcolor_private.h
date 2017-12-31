#ifndef TCOLOR_PRIVATE_H
#define TCOLOR_PRIVATE_H

#include "tabstract_color.h"

namespace tui {

namespace no_public {

///
/// \brief Реализация цвета
///
class TColorPrivate: public TAbstractColor
{
public:
    TColorPrivate( TColors c = TColors::BLACK );
    TColorPrivate( const TColorPrivate &color );
    TColorPrivate( TRgb color );
    TColorPrivate( int red, int green, int blue );
    virtual ~TColorPrivate();
public:
    int red() const;
    int green() const;
    int blue() const;
public:
    void setRed( int value );
    void setGreen( int value );
    void setBlue( int value );
public:
    TColors toEnumColor() const;
public:
    bool operator==( const TColorPrivate &c ) const;
    bool operator!=( const TColorPrivate &c ) const;
    bool operator==( const TColors &c ) const;
    bool operator!=( const TColors &c ) const;
    bool operator==( const TRgb &c ) const;
    bool operator!=( const TRgb &c ) const;
private:
    TColors convert() const;
private:
    int _red;
    int _green;
    int _blue;

    TColors _current;
};

}

}

#endif // TCOLOR_PRIVATE_H
