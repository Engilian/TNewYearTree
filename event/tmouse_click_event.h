#ifndef TMOUSE_CLICK_EVENT_H
#define TMOUSE_CLICK_EVENT_H

#include "tmouse_event.h"

namespace tui {

class TMouseClickEvent : public TMouseEvent
{
public:
    TMouseClickEvent( TMouseButton b, QPoint pos );
    ~TMouseClickEvent();
public:
    TMouseEventType mouseEventType() const;
    TMouseEvent *convertForRelativePos(  QPoint pos  ) const;
};

}



#endif // TMOUSE_CLICK_EVENT_H
