#ifndef TMOUSE_WHEEL_EVENT_H
#define TMOUSE_WHEEL_EVENT_H

#include "tmouse_event.h"

namespace tui {

class TMouseWheelEvent : public TMouseEvent
{
public:
    TMouseWheelEvent( QPoint pos, int delta );
    ~TMouseWheelEvent();
public:
    TMouseEventType mouseEventType() const;
    TMouseEvent *convertForRelativePos(  QPoint pos  ) const;
    int delta() const;
private:
    int     _delta;
};

}



#endif // TMOUSE_WHEEL_EVENT_H
