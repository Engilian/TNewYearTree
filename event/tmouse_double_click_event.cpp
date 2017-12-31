#include "tmouse_double_click_event.h"
using namespace tui;

TMouseDoubleClickEvent::TMouseDoubleClickEvent(TMouseButton b, QPoint pos):
    TMouseEvent( b, pos )
{

}

TMouseDoubleClickEvent::~TMouseDoubleClickEvent()
{

}

TMouseEventType TMouseDoubleClickEvent::mouseEventType() const
{
    return TMouseEventType::DOUBLE_CLICKED_EVENT;
}

TMouseEvent *TMouseDoubleClickEvent::convertForRelativePos(QPoint pos) const
{
    return new TMouseDoubleClickEvent( button (),
                                       TMouseEvent::pos () - pos );
}
