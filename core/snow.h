#ifndef SNOW_H
#define SNOW_H

#include <QObject>
#include <QDateTime>
#include "painter/tpainter.h"

class Snow : public QObject
{
    Q_OBJECT
public:
    explicit Snow(QObject *parent = 0);
    ~Snow();
protected:
    void clear();
    void generateSnow();
    void moveSnow();
public:
    void setRect( QRect rect );
public:
    void paint( tui::TPainter *p );
private:
    QSize           _size;

    QDateTime       _lastGenerate;
    QDateTime       _lastMove;
private:
    QList<QPoint> _points;
signals:

public slots:
};

#endif // SNOW_H
