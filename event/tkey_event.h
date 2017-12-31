#ifndef TKEY_EVENT_H
#define TKEY_EVENT_H

#include <QEvent>

namespace tui {

///
/// \brief Код клавиши
/// \details совместимо с кодами от qt
///
using TKey = int;

///
/// \brief События ввода клавиши
///
class TKeyEvent: public QEvent
{
public:
    TKeyEvent( TKey key, char symbol );
    ~TKeyEvent();
public:
    TKey key() const;
    char symbol() const;
private:
    TKey    _key;
    char    _symbol;
public:
    static const QEvent::Type EventType;

};

}

#endif // TKEY_EVENT_H
