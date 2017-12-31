#ifndef TABSTRACT_PAINTER_DEVICE_H
#define TABSTRACT_PAINTER_DEVICE_H

#include <QObject>
#include <QPoint>
#include <QSize>

#include "event/tresize_event.h"
#include "event/tmove_event.h"
#include "event/tmouse_event.h"
#include "event/tkey_event.h"

namespace tui {

class TPainterDevice;

///
/// \brief Устройство отрисовки
///
class TAbstractPainterDevice: public QObject
{
    Q_OBJECT
protected:
    TAbstractPainterDevice();
public:
    virtual ~TAbstractPainterDevice();
public:
    ///
    /// \brief Установить родительский элемент
    /// \param device устройство
    ///
    virtual void setParent( TPainterDevice *device ) = 0;

    ///
    /// \brief Родительское устройство
    ///
    virtual TPainterDevice *parent() const = 0;
public:
    ///
    /// \brief Область устройства вывода
    ///
    virtual QRect rect() const = 0;
public:
    ///
    /// \brief Текущая позиция
    /// \return позиция верхнего левого угла
    ///
    virtual QPoint pos() const = 0;

    ///
    /// \brief Текущая позиция
    /// \return позиция геометрического центра устройства
    ///
    virtual QPoint centerPos() const = 0;
public:
    ///
    /// \brief Позиция по x
    ///
    virtual int x() const = 0;

    ///
    /// \brief Позиция по y
    ///
    virtual int y() const = 0;

    ///
    /// \brief Позиция по x относительно центра устройства
    ///
    virtual int cx() const = 0;

    ///
    /// \brief Позиция по y относительно центра устройства
    ///
    virtual int cy() const = 0;
public:
    ///
    /// \brief Установить текущую позицию
    /// \param p новая позиция
    ///
    virtual bool move( const QPoint &p ) = 0;

    ///
    /// \brief Установить текущую позицию
    /// \param x позиция по x
    /// \param y позиция по y
    ///
    virtual bool move( int x, int y ) = 0;

    ///
    /// \brief Установить текущую позицию
    /// \param p новая позиция центра
    ///
    virtual bool moveToCenter( const QPoint &p ) = 0;

    ///
    /// \brief Установить текущую позицию
    /// \param x позиция по x
    /// \param y позиция по y
    ///
    virtual bool moveToCenter( int x, int y ) = 0;
public:
    ///
    /// \brief Фактическая позиция устройства на корневом устройстве
    /// \return позиция левого верхнего края
    ///
    virtual QPoint actualPos() const = 0;

    ///
    /// \brief Фактическая позиция устройства на корневом устройстве
    /// \return позиция геометрического цента устройства
    ///
    virtual QPoint actualCenterPos() const = 0;
public:
    ///
    /// \brief Текущий размер устрофства вывода
    /// \return размер
    ///
    virtual QSize size() const = 0;

    ///
    /// \brief Ширина поля вывода
    /// \return ширина в символах
    ///
    virtual int width() const = 0;

    ///
    /// \brief Высота поля вывода
    /// \return высота в символах
    ///
    virtual int height() const = 0;
public:
    ///
    /// \brief Изменить размер отрисовки
    /// \param w ширина
    /// \param h высота
    ///
    virtual bool resize( int w, int h ) = 0;

    ///
    /// \brief Изменить размер отрисовки
    /// \param size новый размер
    ///
    virtual bool resize( const QSize &size ) = 0;
public:
    ///
    /// \brief Инициализация отлова событий нажатия клавиши
    /// \details Следует использовать только в
    ///  главном терминальном виджете
    ///
    virtual void initKeyHandler() = 0;

    ///
    /// \brief Инициализирована ли отлов событий нажатия клавиш
    ///
    virtual bool isInitedKeyHandler() const = 0;

    ///
    /// \brief Остановить отлов событий нажатия клавишь
    ///
    virtual void destroyKeyHandler() = 0;
signals:
    ///
    /// \brief Сигнал изменения размера области
    /// \param event событие
    ///
    void resizeEvent( TResizeEvent *event );

    ///
    /// \brief Сигнал перемещения окна
    /// \param event событие
    ///
    void moveEvent( TMoveEvent *event );

    ///
    /// \brief Сигнал нажатия клавишт
    /// \param event событие
    ///
    void keyEvent( TKeyEvent *event );

    void mouseEvent( TMouseEvent *event );

    ///
    /// \brief Устройство было обновлено
    ///
    void updated();
};

}

#endif // TABSTRACT_PAINTER_DEVICE_H
