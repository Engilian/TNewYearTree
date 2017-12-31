#include "tcolor.h"
using namespace tui;

TColor::TColor(TColors c):
    tui::no_public::TColorPrivate( c )
{

}

TColor::TColor(const TColor &color):
    tui::no_public::TColorPrivate( color )
{

}

TColor::TColor(TRgb color):
    tui::no_public::TColorPrivate( color )
{

}

TColor::TColor(int red, int green, int blue):
    tui::no_public::TColorPrivate( red, green, blue )
{

}

TColor::~TColor()
{

}
