#include "tabstract_painter.h"
using namespace tui;

#include <QDebug>
#include "tpainter_device.h"

TAbstractPainter::TAbstractPainter(TPainterDevice *device)
{
    Q_UNUSED ( device );
}

TAbstractPainter::TAbstractPainter(const TAbstractPainter &c)
{
    Q_UNUSED ( c );
}

TAbstractPainter::~TAbstractPainter()
{

}
