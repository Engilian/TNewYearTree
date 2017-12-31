#include "tcolor_private.h"
using namespace tui;
using namespace tui::no_public;

#include <QList>
#include <tuple>

inline int tRed( TRgb rgb ) {
    return ( ( rgb >> 16 ) & 0xff );
}

inline int tGreen( TRgb rgb ) {
    return ( ( rgb >> 8 ) & 0xff );
}

inline int tBlue( TRgb rgb ) {
    return ( rgb & 0xff );
}

inline TColorPrivate color( TColors c ) {

    switch (c) {
    case TColors::BLACK:
        return TColorPrivate( 0, 0, 0 );
    case TColors::RED:
        return TColorPrivate( 255, 0, 0 );
    case TColors::GREEN:
        return TColorPrivate( 0, 255, 0 );
    case TColors::YELLOW:
        return TColorPrivate( 255, 255, 0 );
    case TColors::BLUE:
        return TColorPrivate( 0, 0, 255 );
    case TColors::MAGENTA:
        return TColorPrivate( 255, 0, 255 );
    case TColors::CYAN:
        return TColorPrivate( 0, 255, 255 );
    case TColors::WHITE:
        return TColorPrivate( 255, 255, 255 );
    }

    return TColors::BLACK;
}

TColorPrivate::TColorPrivate(TColors c):
    _red    ( color(c).red () ),
    _green  ( color(c).green () ),
    _blue   ( color(c).blue () ),
    _current( c )
{

}

TColorPrivate::TColorPrivate(const TColorPrivate &color):
    TAbstractColor( color ),
    _red    ( color.red ()   ),
    _green  ( color.green () ),
    _blue   ( color.blue ()  ),
    _current( color._current )
{

}

TColorPrivate::TColorPrivate(TRgb color):
    _red    ( tRed   ( color ) ),
    _green  ( tGreen ( color ) ),
    _blue   ( tBlue  ( color ) ),
    _current( convert () )
{

}

TColorPrivate::TColorPrivate(int red, int green, int blue):
    _red    ( red ),
    _green  ( green ),
    _blue   ( blue ),
    _current( convert () )
{

}

TColorPrivate::~TColorPrivate()
{

}

int TColorPrivate::red() const
{
    return _red;
}

int TColorPrivate::green() const
{
    return _green;
}

int TColorPrivate::blue() const
{
    return _blue;
}

void TColorPrivate::setRed(int value)
{
    _red = value;

    _current = convert ();
}

void TColorPrivate::setGreen(int value)
{
    _green = value;

    _current = convert ();
}

void TColorPrivate::setBlue(int value)
{
    _blue = value;

    _current = convert ();
}

TColors TColorPrivate::toEnumColor() const
{
    return _current;
}

bool TColorPrivate::operator==(const TColorPrivate &c) const
{
    return ( ( _red == c.red () ) && ( _green == c.green () ) ) &&
            ( _blue == c.blue () );
}

bool TColorPrivate::operator!=(const TColorPrivate &c) const
{
    return !( *this == c );
}

bool TColorPrivate::operator==(const TColors &c) const
{
    return *this == TColorPrivate( c );
}

bool TColorPrivate::operator!=(const TColors &c) const
{
    return *this != TColorPrivate( c );
}

bool TColorPrivate::operator==(const TRgb &c) const
{
    return *this == TColorPrivate( c );
}

bool TColorPrivate::operator!=(const TRgb &c) const
{
    return *this != TColorPrivate( c );
}

TColors TColorPrivate::convert() const
{
    using TColorContainer = std::pair<TColors, std::tuple<int, int, int> >;
    static QList<TColorContainer> colors {
        { TColors::BLACK,   std::make_tuple( 0,     0,      0 ) },
        { TColors::RED,     std::make_tuple( 255,   0,      0 ) },
        { TColors::GREEN,   std::make_tuple( 0,     255,    0 ) },
        { TColors::YELLOW,  std::make_tuple( 255,   255,    0 ) },
        { TColors::BLUE,    std::make_tuple( 0,     0,      255 ) },
        { TColors::MAGENTA, std::make_tuple( 255,   0,      255 ) },
        { TColors::CYAN,    std::make_tuple( 0,     255,    255 ) },
        { TColors::WHITE,   std::make_tuple( 255,   255,    255 ) }
    };

    std::tuple<int, int, int> color = std::make_tuple( _red, _green, _blue );

    for (auto colorConteiner: colors ) {

        auto c = colorConteiner.second;

        if ( c == color ) {

            return colorConteiner.first;
        }
    }

    return TColors::BLACK;
}
