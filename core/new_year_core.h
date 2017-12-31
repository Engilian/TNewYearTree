#ifndef NEWYEARCORE_H
#define NEWYEARCORE_H

#include <QObject>
#include "painter/tpainter_device.h"
#include "painter/tpainter.h"
#include "tree/new_year_tree.h"
#include "snow.h"
#include "event/tresize_event.h"

class NewYearCore : public QObject
{
    Q_OBJECT
public:
    explicit NewYearCore(QObject *parent = 0);
    ~NewYearCore();
protected:
    void timerEvent( QTimerEvent *e );
public:

public:
    void rebuild();
    void repaint();
protected:
    void paint();
    void flush();

private:
    tui::TPainterDevice *_device;
    tui::TPainter       *_painter;

    NewYearTree         *_tree;
    Snow                *_snow;

signals:

public slots:
    void resizeEvent( tui::TResizeEvent *event );
};

#endif // NEWYEARCORE_H
