#include "tmouse_key_event.h"
using namespace tui;

TMouseKeyEvent::TMouseKeyEvent(TMouseButton b, bool pressed, QPoint pos):
    TMouseEvent( b, pos ),
    _pressed( pressed )
{

}

TMouseKeyEvent::~TMouseKeyEvent()
{

}

TMouseEventType TMouseKeyEvent::mouseEventType() const
{
    return TMouseEventType::KEY_EVENT;
}

TMouseEvent *TMouseKeyEvent::convertForRelativePos(QPoint pos) const
{
    return new TMouseKeyEvent(
                button (), _pressed, TMouseEvent::pos () - pos );
}

bool TMouseKeyEvent::isPressed() const
{
    return _pressed;
}

bool TMouseKeyEvent::isReleased() const
{
    return  !_pressed;
}
