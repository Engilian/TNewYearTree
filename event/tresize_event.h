#ifndef TRESIZE_EVENT_H
#define TRESIZE_EVENT_H

#include <QEvent>
#include <QSize>

namespace tui {

///
/// \brief Событие изменения размераы
///
class TResizeEvent: public QEvent
{
public:
    TResizeEvent( const QSize &size, const QSize &old );
public:
    QSize size() const;
    QSize old() const;
private:
    QSize   _size;
    QSize   _old;
public:
    ///
    /// \brief Тип события
    ///
    static const QEvent::Type EventType;
};

}



#endif // TRESIZE_EVENT_H
