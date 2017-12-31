#include "tmouse_move_event.h"
using namespace tui;

TMouseMoveEvent::TMouseMoveEvent(QPoint pos, QPoint oldPos):
    TMouseEvent( TMouseButton::NO_BUTTON, pos ),
    _oldPos( oldPos )
{

}

TMouseMoveEvent::TMouseMoveEvent(TMouseButton b, QPoint pos, QPoint oldPos):
    TMouseEvent( b, pos ),
    _oldPos( oldPos )
{

}

TMouseMoveEvent::~TMouseMoveEvent()
{

}

TMouseEventType TMouseMoveEvent::mouseEventType() const
{
    return TMouseEventType::MOVE_EVENT;
}

TMouseEvent *TMouseMoveEvent::convertForRelativePos(QPoint pos) const
{
    return new TMouseMoveEvent( button (),
                                TMouseEvent::pos () - pos,
                                _oldPos - pos );
}

QPoint TMouseMoveEvent::oldPos() const
{
    return _oldPos;
}
