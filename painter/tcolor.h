#ifndef TCOLOR_H
#define TCOLOR_H

#include "tcolor_private.h"

namespace tui {

class TColor : public no_public::TColorPrivate
{
public:
    TColor( TColors c = TColors::BLACK );
    TColor( const TColor &color );
    TColor( TRgb color );
    TColor( int red, int green, int blue );
    ~TColor();
};

}



#endif // TCOLOR_H
