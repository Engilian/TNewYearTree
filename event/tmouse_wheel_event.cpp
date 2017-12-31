#include "tmouse_wheel_event.h"
using namespace tui;

TMouseWheelEvent::TMouseWheelEvent(QPoint pos, int delta):
    TMouseEvent( TMouseButton::NO_BUTTON, pos ),
    _delta( delta )
{

}

TMouseWheelEvent::~TMouseWheelEvent()
{

}

TMouseEventType TMouseWheelEvent::mouseEventType() const
{
    return TMouseEventType::WHEEL_EVENT;
}

TMouseEvent *TMouseWheelEvent::convertForRelativePos(QPoint pos) const
{
    return new TMouseWheelEvent( TMouseEvent::pos () - pos, _delta );
}

int TMouseWheelEvent::delta() const
{
    return _delta;
}
