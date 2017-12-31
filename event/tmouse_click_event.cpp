#include "tmouse_click_event.h"
using namespace tui;

TMouseClickEvent::TMouseClickEvent(TMouseButton b, QPoint pos):
    TMouseEvent( b, pos )
{

}

TMouseClickEvent::~TMouseClickEvent()
{

}

TMouseEventType TMouseClickEvent::mouseEventType() const
{
    return TMouseEventType::CLICKED_EVENT;
}

TMouseEvent *TMouseClickEvent::convertForRelativePos(QPoint pos) const
{
    return new TMouseClickEvent( button (), TMouseEvent::pos () - pos );
}
