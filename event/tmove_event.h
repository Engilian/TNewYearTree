#ifndef TMOVE_EVENT_H
#define TMOVE_EVENT_H

#include <QEvent>
#include <QPoint>

namespace tui {

class TMoveEvent: public QEvent
{
public:
    TMoveEvent( const QPoint &pos, const QPoint &old );
    ~TMoveEvent();
public:
    QPoint pos() const;
    QPoint old() const;
private:
    QPoint  _pos;
    QPoint  _old;
public:
    static const QEvent::Type EventType;
};

}



#endif // TMOVE_EVENT_H
