#include "area.h"

Area::Area(int w, int h):width(w),height(h)
{
    m_boundingRect=QRectF(0,0,2600,2600);
}


void Area::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->setPen(QPen(Qt::darkGray));

    for(int i=0; i<width;++i)
    {
        painter->drawLine(i*40,0,i*40,2600);
    }


    for(int i=0; i<height;++i)
    {
        painter->drawLine(0,i*40,2600,i*40);
    }
}

QRectF Area::boundingRect() const
{
    return m_boundingRect;
}

void Area::setBoundingRect(QRectF rect)
{
    m_boundingRect=rect;
}
