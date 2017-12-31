#include "tmove_event.h"
using namespace tui;

const QEvent::Type TMoveEvent::EventType = static_cast<QEvent::Type>( 5001 );

TMoveEvent::TMoveEvent(const QPoint &pos, const QPoint &old):
    QEvent ( EventType ),
    _pos( pos ),
    _old( old )
{

}

TMoveEvent::~TMoveEvent()
{

}

QPoint TMoveEvent::pos() const
{
    return _pos;
}

QPoint TMoveEvent::old() const
{
    return _old;
}
