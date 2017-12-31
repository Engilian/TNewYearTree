#ifndef TABSTRACT_PAINTER_H
#define TABSTRACT_PAINTER_H

#include <QPoint>
#include <QLine>
#include <QRect>
#include <QVector>

#include "tcolor.h"
#include "tpen.h"

namespace tui {

class TPainterDevice;

///
/// \brief Класс отрисовки псевдо графических компонентов
///
class TAbstractPainter
{
protected:
    explicit TAbstractPainter(TPainterDevice *device = nullptr);
    TAbstractPainter( const TAbstractPainter &c );
public:
    virtual ~TAbstractPainter();
public:
    virtual TColor backgroundColor() const = 0;
    virtual void setBackgroundColor( const TColor &c ) = 0;
    virtual void setBackgroundColor( TColors c ) = 0;
public: // Методы отрисовки
    virtual void drawPoint(int x, int y, char16_t symbol ) = 0;
    virtual void drawPoint(const QPoint &p, char16_t symbol) = 0;


    virtual void drawLine(int x1, int y1, int x2, int y2,
                  char16_t start, char16_t mid, char16_t end) = 0;
    virtual void drawLine(int x1, int y1, int x2, int y2, const QString &symbols ) = 0;
    virtual void drawLine(const QPoint &p1, const QPoint &p2,
                  char16_t start, char16_t mid, char16_t end) = 0;
    virtual void drawLine(const QPoint &p1, const QPoint &p2, const QString &symbols) = 0;
    virtual void drawLine(const QLine &line, char16_t start, char16_t mid, char16_t end) = 0;
    virtual void drawLine(const QLine &line, const QString &symbols) = 0;

    virtual void drawRect(int x, int y, int w, int h,
                  char16_t tl, char16_t tc, char16_t tr,
                  char16_t cl, char16_t cr,
                  char16_t bl, char16_t bc, char16_t br ) = 0;
    virtual void drawRect(int x, int y, int w, int h, const QString &symbols) = 0;
    virtual void drawRect(const QRect &rect,
                  char16_t tl, char16_t tc, char16_t tr,
                  char16_t cl, char16_t cr,
                  char16_t bl, char16_t bc, char16_t br ) = 0;
    virtual void drawRect(const QRect &rect, const QString &symbols) = 0;

    virtual void fillRect(int x, int y, int w, int h, const TColor &color) = 0;
    virtual void fillRect(const QRect &r, const TColor &color) = 0;

    virtual void fillRect(int x, int y, int w, int h, TRgb c) = 0;
    virtual void fillRect(const QRect &r, TRgb c) = 0;

public:
    virtual void drawText ( QRect &r, QString &text ) = 0;
    virtual void drawText ( QPoint p0, int w, int h, QString &text ) = 0;
public:
    ///
    /// \brief Получить текущий карандаш
    ///
    virtual TPen &pen() = 0;

    ///
    /// \brief Установить карандаш
    /// \param pen карандаш
    ///
    virtual void setPen( const TPen &pen ) = 0;
public:
    virtual void flush() = 0;
public:
    virtual void clearAll() = 0;
public:
    ///
    /// \brief Устройство отрисовки
    ///
    virtual TPainterDevice *device() const = 0;

    ///
    /// \brief Установить устройство отрисовки
    /// \param device устройство
    ///
    virtual void setDevice( TPainterDevice *device ) = 0;
};

}



#endif // TABSTRACT_PAINTER_H
