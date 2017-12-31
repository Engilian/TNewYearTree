#include "tkey_event.h"
using namespace tui;

const QEvent::Type TKeyEvent::EventType = static_cast<QEvent::Type>( 5005 );

TKeyEvent::TKeyEvent(TKey key, char symbol):
    QEvent  ( EventType ),
    _key    ( key ),
    _symbol ( symbol )
{

}

TKeyEvent::~TKeyEvent()
{

}

TKey TKeyEvent::key() const
{
    return _key;
}

char TKeyEvent::symbol() const
{
    return _symbol;
}
