#include "ncurses_painter.h"

#include <QDebug>

#include "tpainter_device.h"
#include "ncurses_painter_device.h"
#include <ncurses.h>



#define PDEVICE() \
    std::shared_ptr<NCursesPainterDevice> p; \
    WINDOW  *window     = nullptr; \
    Q_UNUSED ( p );Q_UNUSED ( window ); \
    if ( _painterDevice ) p = device()->convert<NCursesPainterDevice>(); \
    if ( !p ) return; \
    window  = p->_window


NCursesPainter::NCursesPainter(tui::TPainterDevice *device):
    tui::TAbstractPainter ( device ),
    _backgroundColor( tui::TColors::WHITE ),
    _painterDevice( device )
{

}

NCursesPainter::~NCursesPainter()
{

}

tui::TColor NCursesPainter::backgroundColor() const
{
    return _backgroundColor;
}

void NCursesPainter::setBackgroundColor(const tui::TColor &c)
{
    PDEVICE();

    _backgroundColor = c;

    if ( window ) {

        wbkgd ( window, COLOR_PAIR ( getBindColor ( c, c ) ) );
    }
    else {

        bkgd ( COLOR_PAIR ( getBindColor ( c, c ) ) );
    }

    _pen.setBackgroundColor ( c );
}

void NCursesPainter::setBackgroundColor(tui::TColors c)
{
    tui::TColor tc( c );
    setBackgroundColor ( tc );
}

void NCursesPainter::drawPoint(int x, int y, char16_t symbol)
{
    QPoint p( x, y );
    drawPoint( p, symbol );
}


void NCursesPainter::drawPoint(const QPoint &point, char16_t symbol)
{
    PDEVICE();
    bindPen();

    mv( point );

    if ( window ) {
        wprintw ( window, "%c", symbol );
    }
    else {
        printw ( "%c", symbol );
    }
}

void NCursesPainter::drawLine(int x1, int y1, int x2, int y2, char16_t start, char16_t mid, char16_t end)
{
    PDEVICE();

    bindPen ();

    double width   = x2 - x1;
    double height  = y2 - y1;

    int length  = static_cast<int>(
                std::round (
                    std::sqrt ( std::pow ( x2 - x1, 2 ) + std::pow ( y2 - y1, 2 ) )
                    )
                );

    double stepX = ( width / length );
    double stepY = ( height / length );

    if ( window ) {

        double dx = static_cast<double>( x1 );
        double dy = static_cast<double>( y1 );

        for ( int i = 0; i <= length; ++i, dx += stepX, dy += stepY ) {

            mv( static_cast<int>( std::round ( dx ) ),
                static_cast<int>( std::round ( dy ) ) );
            wprintw ( window, "%c", mid );
        }
    }
    else {

        double dx = static_cast<double>( x1 );
        double dy = static_cast<double>( y1 );



        for ( int i = 0; i <= length; ++i, dx += stepX, dy += stepY ) {

            mv( static_cast<int>( std::round ( dx ) ),
                static_cast<int>( std::round ( dy ) ) );
            printw ( "%c", mid );
        }
    }

    drawPoint( x1, y1, start );
    drawPoint( x2, y2, end );
}

void NCursesPainter::drawLine(int x1, int y1, int x2, int y2, const QString &symbols)
{
    drawLine( x1,y1, x2, y2,
              symbols[0].toLatin1(),
            symbols[1].toLatin1(),
            symbols[2].toLatin1());
}

void NCursesPainter::drawLine(const QPoint &p1, const QPoint &p2, char16_t start, char16_t mid, char16_t end)
{
    drawLine( p1.x(), p1.y(), p2.x(), p2.y(), start, mid, end );
}

void NCursesPainter::drawLine(const QPoint &p1, const QPoint &p2, const QString &symbols)
{
    drawLine( p1.x(), p1.y(), p2.x(), p2.y(), symbols );
}

void NCursesPainter::drawLine(const QLine &line, char16_t start, char16_t mid, char16_t end)
{
    drawLine( line.x1(), line.y1(), line.x2(), line.y2(),
              start, mid, end );
}

void NCursesPainter::drawLine(const QLine &line, const QString &symbols)
{
    drawLine( line.x1(), line.y1(), line.x2(), line.y2(),
              symbols );
}

void NCursesPainter::drawRect(int x, int y, int w, int h, char16_t tl, char16_t tc, char16_t tr, char16_t cl, char16_t cr, char16_t bl, char16_t bc, char16_t br)
{
    QRect r( x, y, w, h );
    drawRect( r, tl, tc, tr, cl, cr, bl, bc, br);
}

void NCursesPainter::drawRect(int x, int y, int w, int h, const QString &symbols)
{
    QRect r( x, y, w, h );
    drawRect( r,symbols );
}

void NCursesPainter::drawRect(const QRect &rect, char16_t tl, char16_t tc, char16_t tr, char16_t cl, char16_t cr, char16_t bl, char16_t bc, char16_t br)
{
    PDEVICE();

    bindPen ();

    // Левая

    drawLine( rect.topLeft(), rect.bottomLeft(), tl, cl, bl );
    // Верхняя

    drawLine( rect.topLeft(), rect.topRight(), tl, tc, tr );
    // Праввая

    drawLine( rect.topRight(), rect.bottomRight(), tr, cr, br );
    // Нижняя

    drawLine( rect.bottomLeft(), rect.bottomRight(), bl, bc, br );

}

void NCursesPainter::drawRect(const QRect &rect, const QString &symbols)
{
    drawRect( rect,
              symbols[0].toLatin1(), symbols[1].toLatin1(), symbols[2].toLatin1(),
            symbols[3].toLatin1(), symbols[4].toLatin1(),
            symbols[5].toLatin1(), symbols[6].toLatin1(), symbols[7].toLatin1() );
}

void NCursesPainter::fillRect(int x, int y, int w, int h, const tui::TColor &color)
{
    PDEVICE();
    bindColor ( color, color  );

    if ( window ) {

        for ( int i = x; i < x + w; ++i ) {

            for ( int j = y; j < y + h; ++j ) {

                mv( i, j );
                wprintw ( window, "%s", "#" );
            }

            flush ();
        }
    }
    else {

        for ( int i = x; i <= x + w; ++i ) {

            for ( int j = y; j <= y + h; ++j ) {

                mv( i, j );
                printw ( "%s", " " );
            }
        }
    }
}

void NCursesPainter::fillRect(const QRect &r, const tui::TColor &color)
{
    fillRect ( r.x (), r.y (), r.width (), r.height (), color );
}

void NCursesPainter::fillRect(int x, int y, int w, int h, tui::TRgb c)
{
    fillRect ( x, y, w, h, tui::TColor( c ) );
}

void NCursesPainter::fillRect(const QRect &r, tui::TRgb c)
{
    fillRect ( r.x (), r.y (), r.width (), r.height (), c );
}

void NCursesPainter::drawText(QRect &r, QString &text)
{
    QPoint pos( r.x (), r.y () );
    drawText ( pos, r.width (), r.height (), text );
}

void NCursesPainter::drawText(QPoint p0, int w, int h, QString &text)
{
    PDEVICE();
    bindPen ();

    mv( p0 );

    QRect rect ( p0, QPoint( p0.x () + w, p0.y () + h ) );

    int x = p0.x ();
    int y = p0.y ();

    for ( int i = 0; i < text.count (); ++i ) {

        mv( x, y );

        if ( text[ i ] != '\n' ) {

            if ( window ) {
                wprintw ( window, "%s", QString( text[ i ] ).toStdString ().c_str () );
            }
            else {
                printw ( "%s", QString( text[ i ] ).toStdString ().c_str () );
            }
        }
        else {
            x = p0.x ();
            ++y;
        }

        ++x;
        if ( x >= rect.topRight ().x () ) {
            ++y;
            x = p0.x ();
        }

        if ( y >= rect.bottomRight ().y () ) {

            break;
        }
    }
}

tui::TPen &NCursesPainter::pen()
{
    return _pen;
}

void NCursesPainter::setPen(const tui::TPen &pen)
{
    _pen = pen;
}

void NCursesPainter::clearAll()
{
    PDEVICE();

    if ( window ) {
        wclear ( window );
    }
    else {
        clear ();
    }
}

tui::TPainterDevice *NCursesPainter::device() const
{
    return _painterDevice;
}

void NCursesPainter::setDevice(tui::TPainterDevice *device)
{
    _painterDevice = device;
}

void NCursesPainter::flush()
{
    PDEVICE();

    if ( window ) {

        wrefresh ( window );
        //        update_panels();
        //        doupdate();
    }
    else {
        refresh ();
    }
}

void NCursesPainter::mv(int x, int y)
{
    PDEVICE();

    if ( window ) {
        wmove( window, y, x );
    }
    else {
        move( y, x );
    }
}

void NCursesPainter::mv(QPoint p)
{
    mv( p.x (), p.y () );
}

void NCursesPainter::bindPen()
{
    bindColor ( _pen.backgroundColor (), _pen.color () );
}

void NCursesPainter::bindColor(const tui::TColor &b, const tui::TColor &c)
{
    bindColor ( b.toEnumColor (), c.toEnumColor () );
}

void NCursesPainter::bindColor(tui::TColors b, tui::TColors c)
{
    PDEVICE();

    if ( window ) {

        wattron( window, COLOR_PAIR ( getBindColor( b, c ) ) );
    }
    else {

        attron( COLOR_PAIR ( getBindColor( b, c ) ) );
    }

}

short NCursesPainter::getColor(const tui::TColors &c)
{
    switch ( c ) {
    case tui::TColors::BLACK:
        return COLOR_BLACK;
    case tui::TColors::RED:
        return COLOR_RED;
    case tui::TColors::GREEN:
        return COLOR_GREEN;
    case tui::TColors::YELLOW:
        return COLOR_YELLOW;
    case tui::TColors::BLUE:
        return COLOR_BLUE;
    case tui::TColors::MAGENTA:
        return COLOR_MAGENTA;
    case tui::TColors::CYAN:
        return COLOR_CYAN;
    case tui::TColors::WHITE:
        return COLOR_WHITE;
    }

    return COLOR_BLACK;
}

short NCursesPainter::getBindColor(const tui::TColor &b, const tui::TColor &c)
{
    return getBindColor ( b.toEnumColor (), c.toEnumColor () );
}

short NCursesPainter::getBindColor(tui::TColors b, tui::TColors c)
{
    static QMap<short, short>   colors;
    static short            index       = 1;

    short key = ( getColor (b) * 10 ) + getColor(c);

    if ( !colors.contains ( key ) ) {

        short bColor    = getColor(b);
        short color     = getColor(c);

        colors[ key ] = index;
        init_pair( index, color, bColor );

        ++index;

    }

    return colors[ key ];
}


#undef PDEVICE
