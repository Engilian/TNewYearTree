#include "tabstract_color.h"
using namespace tui;

TAbstractColor::TAbstractColor(TColors c)
{
    Q_UNUSED ( c );
}

TAbstractColor::TAbstractColor(TRgb color)
{
    Q_UNUSED ( color );
}

TAbstractColor::TAbstractColor(int red, int green, int blue)
{
    Q_UNUSED ( red ); Q_UNUSED ( green ); Q_UNUSED ( blue );
}

TAbstractColor::~TAbstractColor()
{

}
