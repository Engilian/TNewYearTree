#include "tpainter.h"
using namespace tui;

TPainter::TPainter(TPainterDevice *device):
    no_public::TPainterPrivate (device)
{

}

TPainter::TPainter(const TPainter &painter):
    no_public::TPainterPrivate ( painter )
{

}

TPainter::~TPainter()
{

}
