#ifndef TMOUSE_DOUBLE_CLICK_EVENT_H
#define TMOUSE_DOUBLE_CLICK_EVENT_H

#include "tmouse_event.h"

namespace tui {


class TMouseDoubleClickEvent : public TMouseEvent
{
public:
    TMouseDoubleClickEvent( TMouseButton b, QPoint pos );
    ~TMouseDoubleClickEvent();
public:
    TMouseEventType mouseEventType() const;
    TMouseEvent *convertForRelativePos(  QPoint pos  ) const;
};

}

#endif // TMOUSE_DOUBLE_CLICK_EVENT_H
