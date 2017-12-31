#ifndef TMOUSE_KEY_EVENT_H
#define TMOUSE_KEY_EVENT_H

#include "tmouse_event.h"

namespace tui {

/// Событие нажатия кнопки мыши
class TMouseKeyEvent : public TMouseEvent
{
public:
    TMouseKeyEvent(TMouseButton b, bool pressed, QPoint pos);
    ~TMouseKeyEvent();
public:
    TMouseEventType mouseEventType() const;
    TMouseEvent *convertForRelativePos(  QPoint pos  ) const;
public:
    bool isPressed() const;
    bool isReleased() const;
private:
    bool    _pressed;
};

}



#endif // TMOUSE_KEY_EVENT_H
