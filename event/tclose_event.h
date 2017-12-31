#ifndef TCLOSE_EVENT_H
#define TCLOSE_EVENT_H

#include <QEvent>

namespace tui {

class TCloseEvent: public QEvent
{
public:
    TCloseEvent();
    ~TCloseEvent();
public:
    static const QEvent::Type EventType;
};

}



#endif // TCLOSE_EVENT_H
