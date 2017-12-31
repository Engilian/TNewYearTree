#ifndef TMOUSE_EVENT_H
#define TMOUSE_EVENT_H

#include <QEvent>
#include <QPoint>

namespace tui {

class TWidget;

///
/// \brief Тип кнопки
///
enum class TMouseButton {

    NO_BUTTON       = 0,
    LEFT_BUTTON     = 1,
    RIGHT_BUTTON    = 2,
    MIDDLE_BUTTON   = 3
};

enum class TMouseEventType {

    KEY_EVENT,
    CLICKED_EVENT,
    DOUBLE_CLICKED_EVENT,
    MOVE_EVENT,
    WHEEL_EVENT
};

class TMouseEvent: public QEvent
{
public:
    TMouseEvent( TMouseButton b, QPoint pos );
    ~TMouseEvent();
public:
    TMouseButton button() const;
    QPoint pos() const;
public:
    ///
    /// \brief Тип события мыши
    ///
    virtual TMouseEventType mouseEventType() const = 0;

    ///
    /// \brief Преобразовать событие мыши для
    /// \param pos позиция относительно которой будет происходить измененение
    /// \return событие для обработки в виджете
    ///
    virtual TMouseEvent *convertForRelativePos( QPoint pos ) const = 0;
private:
    TMouseButton    _button;
    QPoint          _pos;
public:
    static const QEvent::Type EventType;
};

}



#endif // TMOUSE_EVENT_H
