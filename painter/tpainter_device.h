#ifndef TPAINTER_DEVICE_H
#define TPAINTER_DEVICE_H

#include "tpainter_device_private.h"

namespace tui {

///
/// \brief Устройство вывода
///
class TPainterDevice: public no_public::TPainterDevicePrivate
{
    Q_OBJECT
public:
    TPainterDevice();
    TPainterDevice( TPainterDevice *parent );
    ~TPainterDevice();
};


}


#endif // TPAINTER_DEVICE_H
