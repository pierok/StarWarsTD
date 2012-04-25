#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H

#include <QtGui>

class CustomView : public QGraphicsView
{
    Q_OBJECT
public:
    CustomView(QWidget *parent = 0);
    int x;
    int y;

private:
    ;

public slots:
    void mouseMoveEvent ( QMouseEvent * event );
};

#endif // CUSTOMVIEW_H
