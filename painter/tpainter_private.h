#ifndef TPAINTER_PRIVATE_H
#define TPAINTER_PRIVATE_H

#include "tobject_private.h"
#include "tabstract_painter.h"

namespace tui {

class TAbstractPainterDevice;

namespace no_public {

class TPainterPrivate : public TAbstractPainter, public TObjectPrivate<TAbstractPainter>
{
public:
    TPainterPrivate( TPainterDevice *device = nullptr );
    TPainterPrivate( const TPainterPrivate &p );
    ~TPainterPrivate();
public:
    TColor backgroundColor() const;
    void setBackgroundColor( const TColor &c );
    void setBackgroundColor( TColors c );
public: // Методы отрисовки
    void drawPoint(int x, int y, char16_t symbol );
    void drawPoint(const QPoint &p, char16_t symbol);

    void drawLine(int x1, int y1, int x2, int y2,
                  char16_t start, char16_t mid, char16_t end);

    void drawLine(int x1, int y1, int x2, int y2, const QString &symbols );

    void drawLine(const QPoint &p1, const QPoint &p2,
                  char16_t start, char16_t mid, char16_t end);

    void drawLine(const QPoint &p1, const QPoint &p2, const QString &symbols);

    void drawLine(const QLine &line, char16_t start, char16_t mid, char16_t end);

    void drawLine(const QLine &line, const QString &symbols);



    void drawRect(int x, int y, int w, int h,
                  char16_t tl, char16_t tc, char16_t tr,
                  char16_t cl, char16_t cr,
                  char16_t bl, char16_t bc, char16_t br );

    void drawRect(int x, int y, int w, int h, const QString &symbols);

    void drawRect(const QRect &rect,
                  char16_t tl, char16_t tc, char16_t tr,
                  char16_t cl, char16_t cr,
                  char16_t bl, char16_t bc, char16_t br );

    void drawRect(const QRect &rect, const QString &symbols);

    void fillRect(int x, int y, int w, int h, const TColor &color);
    void fillRect(const QRect &r, const TColor &color);

    void fillRect(int x, int y, int w, int h, TRgb c);
    void fillRect(const QRect &r, TRgb c);
public:
    void drawText ( QRect &r, QString &text );
    void drawText ( QPoint p0, int w, int h, QString &text );
public:
    TPen &pen();
    void setPen( const TPen &pen );
public:
    void clearAll();
    void flush();
public:
    TPainterDevice *device() const;
    void setDevice( TPainterDevice *device );
};

}

}



#endif // TPAINTER_PRIVATE_H
