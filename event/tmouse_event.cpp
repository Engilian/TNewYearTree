#include "tmouse_event.h"
using namespace tui;

const QEvent::Type TMouseEvent::EventType = static_cast<QEvent::Type>( 5006 );

TMouseEvent::TMouseEvent( TMouseButton b, QPoint pos ):
    QEvent (EventType),
    _button( b ),
    _pos( pos )
{

}

TMouseEvent::~TMouseEvent()
{

}

TMouseButton TMouseEvent::button() const
{
    return _button;
}

QPoint TMouseEvent::pos() const
{
    return _pos;
}
