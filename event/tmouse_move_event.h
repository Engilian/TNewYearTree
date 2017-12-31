#ifndef TMOUSE_MOVE_EVENT_H
#define TMOUSE_MOVE_EVENT_H

#include "tmouse_event.h"

namespace tui {

///
/// \brief Событие перемещения мыши
///
class TMouseMoveEvent : public TMouseEvent
{
public:
    TMouseMoveEvent( QPoint pos, QPoint oldPos );
    TMouseMoveEvent( TMouseButton b, QPoint pos, QPoint oldPos );
    ~TMouseMoveEvent();
public:
    TMouseEventType mouseEventType() const;
    TMouseEvent *convertForRelativePos(  QPoint pos  ) const;
    QPoint oldPos() const;
private:
    QPoint  _oldPos;
};

}



#endif // TMOUSE_MOVE_EVENT_H
