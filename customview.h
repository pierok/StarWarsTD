#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H

#include <QtGui>
#include <QtOpenGL>
#include <QGraphicsView>

class CustomView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CustomView(QObject *parent = 0);
    int x;
    int y;

private:
    ;

public slots:
    void mouseMoveEvent ( QMouseEvent * event );
};

#endif // CUSTOMVIEW_H
