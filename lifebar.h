#ifndef LIFEBAR_H
#define LIFEBAR_H
#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>
#include <QPen>
#include <QColor>

class LifeBar : public QGraphicsItem
{
public:
    LifeBar(int life,int size);

    QRectF boundingRect() const;
    void setBoundingRect(QRectF);

    void control();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    inline void updateLife(int l)
    {
        if(life>1)
        life=l;
    }




    int life;
    int size;
private:
    QRectF m_boundingRect;
    double sizeLife;
    //int life;

};

#endif // LIFEBAR_H
