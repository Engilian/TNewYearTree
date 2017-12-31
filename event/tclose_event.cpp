#include "tclose_event.h"
using namespace tui;

const QEvent::Type TCloseEvent::EventType = static_cast<QEvent::Type>( 5003 );

TCloseEvent::TCloseEvent(): QEvent ( EventType )
{

}

TCloseEvent::~TCloseEvent()
{

}
