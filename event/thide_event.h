#ifndef THIDE_EVENT_H
#define THIDE_EVENT_H

#include <QEvent>

namespace tui {

class THideEvent: public QEvent
{
public:
    THideEvent();
    ~THideEvent();
public:
    static const QEvent::Type EventType;
};

}



#endif // THIDE_EVENT_H
