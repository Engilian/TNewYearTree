#ifndef TPAINTER_H
#define TPAINTER_H

#include "tpainter_private.h"

namespace tui {

///
/// \brief Устройство отрисовки
///
class TPainter: public no_public::TPainterPrivate
{
public:
    TPainter( TPainterDevice *device );
    TPainter( const TPainter &painter );
    ~TPainter();

};

}



#endif // TPAINTER_H
