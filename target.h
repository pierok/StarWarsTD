#ifndef TARGET_H
#define TARGET_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>

class Target: public QGraphicsItem
{
public:
    Target();
    virtual void step()=0;
    virtual void hit(double i)=0;
    int radius;
    bool deactive;
};


#endif // TARGET_H
