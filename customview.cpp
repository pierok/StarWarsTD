#include "customview.h"
#include <iostream>

CustomView::CustomView(QObject* parent )  //: QGraphicsView(parent)
{

    std::cout<<"CustomView"<<std::endl;
    this->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
    this->setRenderHint(QPainter::Antialiasing);
    this->setBackgroundBrush(QPixmap(":/data/gw.jpg"));
    //this->setBackgroundBrush(QColor(30,0,40));
    this->setCacheMode(QGraphicsView::CacheBackground);
    this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    this->setStyleSheet( "QGraphicsView { border-style: none; }" );
    this->setDragMode(QGraphicsView::NoDrag);
    //this->setCursor(Qt::CrossCursor);
    this->setMouseTracking(true);

    x=0;
    y=0;
}

void CustomView::mouseMoveEvent ( QMouseEvent * event )
{
    x = event->x();
    y = event->y();
    event->accept();
}
