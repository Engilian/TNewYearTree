#include "tresize_event.h"
using namespace tui;

 const QEvent::Type TResizeEvent::EventType = static_cast<QEvent::Type>( 5000 );

TResizeEvent::TResizeEvent(const QSize &size, const QSize &old):
    QEvent ( EventType ),
    _size( size ),
    _old ( old )
{

}

QSize TResizeEvent::old() const
{
    return _old;
}

QSize TResizeEvent::size() const
{
    return _size;
}
