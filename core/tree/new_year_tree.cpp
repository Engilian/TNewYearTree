#include "new_year_tree.h"
using namespace tui;

NewYearTree::NewYearTree(QObject *parent) :
    QObject(parent),
    _pos    ( 0, 0 ),
    _size   ( 60, 23 ),
    _lampColors { TColors::RED, TColors::BLUE, TColors::YELLOW, TColors::MAGENTA },
    _startColors { TColors::RED, TColors::GREEN, TColors::BLUE },
    _boxesColor {  TColors::RED, TColors::GREEN, TColors::BLUE, TColors::MAGENTA, TColors::YELLOW },

    _lastUpdateGarland  ( QDateTime::currentDateTime() ),
    _lastUpdateStar     ( QDateTime::currentDateTime() )
{

    generateTree();
}

NewYearTree::~NewYearTree()
{

}

void NewYearTree::paint(tui::TPainter *p)
{
    TPen pen( TColors::BLACK, TColors::GREEN );
    p->setPen( pen );

    {
        int w = _size.width() * 0.1;
        QPoint p1 (
                    _topCenter.x() - ( w / 2 ),
                    _topCenter.y() + _size.height() - 3
                    );

        while ( p1.y() < _topCenter.y() + _size.height() ) {

            QPoint p2 ( p1.x() + w, p1.y() );
            p->drawLine( p1, p2, "|-|" );

            p1.setY( p1.y() + 1 );
        }

    }

    p->drawPoint( _topCenter, '^' );
    for ( auto l: _lines ) {

        p->drawLine( l, U'/', U'~', U'\\' );
//        p->drawLine( l, "/~\\" );
    }

    paintStar( p );
    paintGarland( p );
}

void NewYearTree::paintStar(TPainter *p)
{
    if ( _lastUpdateStar.msecsTo( QDateTime::currentDateTime() ) >= 200 ) {

        _startColors    <<  _startColors.takeFirst();
        _lastUpdateStar =   QDateTime::currentDateTime();
    }

    TPen pen ( TColors::BLACK, _startColors.first() );
    p->setPen( pen );

    QPoint point ( _topCenter.x(), _topCenter.y() - 1 );
    p->drawPoint( point, u'*');
}

void NewYearTree::paintGarland(TPainter *p)
{
    paintBaseGarlandMode( p );
}

void NewYearTree::paintBaseGarlandMode(TPainter *p)
{
    if ( _garland.isEmpty() ) return;

    if ( _lastUpdateGarland.msecsTo( QDateTime::currentDateTime() ) >= 200 ) {

        _garland            <<  _garland.takeFirst();
        _lastUpdateGarland  =   QDateTime::currentDateTime();
    }

    QList<TColors> colors = _lampColors;

    for ( auto &point: _garland ) {

        TPen pen ( TColors::BLACK, colors.first() );
        p->setPen( pen );

        p->drawPoint( point, 'O');

        colors << colors.takeFirst();
    }
}

void NewYearTree::generateTree()
{
    _lines.clear();
    _garland.clear();

    _topCenter = QPoint(
                _pos.x() + ( _size.width() / 2 ),
                _pos.y()
                );

    int x   = _topCenter.x();
    int y   = _topCenter.y() + 1;

    int ey      = _pos.y() + _size.height() - 3;
    int step    = 2;
    int ty      = y + step;
    for ( int i = 1; y < ey; i += 1, ++y ) {

        if ( y == ty ) {

            i = i * 0.65;
//            i = i - 2;
            step += 1;
            ty += step;
        }

        QPoint p1 ( x - i, y );
        QPoint p2 ( x + i, y );

        QLine l ( p1, p2 );

        _lines << l;
    }


    QList<QLine> lines = _lines;

    if ( lines.isEmpty() ) return;

    lines.removeFirst();

    if ( lines.isEmpty() ) return;

    lines.removeFirst();

    if ( lines.isEmpty() ) return;

    x = 0;
    int lx = 0;
    for ( auto &l: lines ) {

        if ( x < l.x1() || x > l.x2() - 1 ) {

            int nx = l.x1() + 1 + std::max( 0, x - l.x2() );
            x = std::min( nx, l.x2() - 1 );

            if ( x == lx ) {
                --x;
            }
        }

        _garland << QPoint( x, l.y1() );

        lx = x;
        x += 5;
    }
}

QRect NewYearTree::rect() const
{
    QRect r( _pos, _size );
    return r;
}

QSize NewYearTree::size() const
{
    return _size;
}

QPoint NewYearTree::pos() const
{
    return _pos;
}

void NewYearTree::setRect(QRect rect)
{
    _pos = rect.topLeft();
    _size = rect.size();

    generateTree();
}

