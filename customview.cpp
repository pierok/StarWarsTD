#include "customview.h"

CustomView::CustomView(QWidget *parent )  : QGraphicsView(parent)
{
    x=0;
    y=0;
}

void CustomView::mouseMoveEvent ( QMouseEvent * event )
{
    x = event->x();
    y = event->y();
    event->accept();
}
