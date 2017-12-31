#include "thide_event.h"
using namespace tui;

const QEvent::Type THideEvent::EventType = static_cast<QEvent::Type>( 5002 );

THideEvent::THideEvent(): QEvent ( EventType )
{

}

THideEvent::~THideEvent()
{

}
