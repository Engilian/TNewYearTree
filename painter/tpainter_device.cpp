#include "tpainter_device.h"
using namespace tui;

TPainterDevice::TPainterDevice():
    no_public::TPainterDevicePrivate ()
{

}

TPainterDevice::TPainterDevice(TPainterDevice *parent):
    no_public::TPainterDevicePrivate ( parent )
{

}

TPainterDevice::~TPainterDevice()
{

}
