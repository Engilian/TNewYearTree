#include "snow.h"
using namespace tui;

Snow::Snow(QObject *parent) :
    QObject(parent),
    _size           ( 10, 10 ),
    _lastGenerate   ( QDateTime::currentDateTime() ),
    _lastMove       ( QDateTime::currentDateTime() )
{

}

Snow::~Snow()
{

}

void Snow::clear()
{
    _points.clear();
}

void Snow::generateSnow()
{
    if ( _size.width() <= 0 ) return;

    if ( _lastGenerate.msecsTo( QDateTime::currentDateTime() ) < 200 ) {

        return;
    }

    int min = _size.width() * 0.01;
    int max = _size.width() * 0.05;

    int gen = min + ( rand() % ( max - min ) );

    for ( int i = 0; i < gen; ++i ) {

        QPoint point (
                    rand() % _size.width(),
                    0
                    );

        _points << point;
    }

    _lastGenerate = QDateTime::currentDateTime();
}

void Snow::moveSnow()
{
    if ( _lastMove.msecsTo( QDateTime::currentDateTime() ) < 300 ) {

        return;
    }

    for ( auto &point: _points ) {

        point.setY( point.y() + 1 );
    }

    QList<QPoint> points;

    for ( auto &p: _points ) {

        if ( p.y() < _size.height() ) {

            points << p;
        }
    }

    _points = points;

    _lastMove = QDateTime::currentDateTime();
}

void Snow::setRect(QRect rect)
{

    _size = rect.size();
    clear();
}

void Snow::paint(tui::TPainter *p)
{
    TPen pen( TColors::BLACK, TColors::WHITE );
    p->setPen( pen );

    generateSnow();
    moveSnow();

    for ( auto &point: _points ) {

        p->drawPoint( point, '*' );
    }
}

