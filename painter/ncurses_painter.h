#ifndef NCURSES_PAINTER_H
#define NCURSES_PAINTER_H

#include "tabstract_painter.h"


class NCursesPainter: public tui::TAbstractPainter
{
public:
    NCursesPainter(tui::TPainterDevice *device);
    ~NCursesPainter();

    //------------------------------------------------------- Методы интерфейса
public: // Управление цветом фона

    tui::TColor backgroundColor() const;
    void setBackgroundColor( const tui::TColor &c );
    void setBackgroundColor( tui::TColors c );
public: // Методы отрисовки

    /*
     *  Отрисовка точек
     */

    void drawPoint(int x, int y, char16_t symbol );
    void drawPoint(const QPoint &point, char16_t symbol);


    /*
     * Отрисовка линий
     */
    void drawLine(int x1, int y1, int x2, int y2,
                  char16_t start, char16_t mid, char16_t end);

    void drawLine(int x1, int y1, int x2, int y2, const QString &symbols );

    void drawLine(const QPoint &p1, const QPoint &p2,
                  char16_t start, char16_t mid, char16_t end);

    void drawLine(const QPoint &p1, const QPoint &p2, const QString &symbols);

    void drawLine(const QLine &line, char16_t start, char16_t mid, char16_t end);

    void drawLine(const QLine &line, const QString &symbols);

    /*
     * Отрисовка прямоугольников
     */
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


    /*
     * Заливка области
     */
    void fillRect(int x, int y, int w, int h, const tui::TColor &color);
    void fillRect(const QRect &r, const tui::TColor &color);

    void fillRect(int x, int y, int w, int h, tui::TRgb c);
    void fillRect(const QRect &r, tui::TRgb c);

    /*
     * Отрисовка текста
     */

    void drawText ( QRect &r, QString &text );
    void drawText ( QPoint p0, int w, int h, QString &text );

public: // Карандаш
    tui::TPen &pen();
    void setPen( const tui::TPen &pen );

public: // Методы управления выводом
    void flush();
    void clearAll();

public: // Методы управление устройством вывода
    tui::TPainterDevice *device() const;
    void setDevice( tui::TPainterDevice *device );

//------------------------------------------------------- Внутрение методы
protected:
    void mv( int x, int y );
    void mv( QPoint p );
    void bindPen();
    void bindColor( const tui::TColor &b, const tui::TColor &c );
    void bindColor( tui::TColors b, tui::TColors c );
public:

    static short getColor( const tui::TColors &c );

    static short getBindColor( const tui::TColor &b, const tui::TColor &c );
    static short getBindColor( tui::TColors b, tui::TColors c );
public:

    ///
    /// \brief Цвет фона
    ///
    tui::TColor             _backgroundColor;

    ///
    /// \brief Устройство отрисовки
    ///
    tui::TPainterDevice     *_painterDevice;

    tui::TPen               _pen;
};

#endif // NCURSES_PAINTER_H
