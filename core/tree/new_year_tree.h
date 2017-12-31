#ifndef NEWYEARTREE_H
#define NEWYEARTREE_H

#include <QObject>
#include <QPoint>
#include <QRect>

#include <QDateTime>

#include "painter/tpainter.h"

class NewYearTree : public QObject
{
    Q_OBJECT
public:
    explicit NewYearTree(QObject *parent = 0);
    ~NewYearTree();
public:
    QRect rect() const;
    QSize size() const;
    QPoint pos() const;
public:
    void setRect( QRect rect );
public:
    void paint( tui::TPainter *p );
    void paintStar( tui::TPainter *p ) ;
    void paintGarland( tui::TPainter * p );
    void paintBaseGarlandMode( tui::TPainter * p );
protected:
    void generateTree();
private:
    QPoint          _pos;
    QSize           _size;
public:
    QPoint          _topCenter;
    QList<QLine>    _lines;
    QList<QPoint>   _garland;
    QList<QRect>    _boxes;

    QList<tui::TColors> _lampColors;
    QList<tui::TColors> _startColors;
    QList<tui::TColors> _boxesColor;


    QDateTime       _lastUpdateGarland;
    QDateTime       _lastUpdateStar;
signals:

public slots:
};

#endif // NEWYEARTREE_H
