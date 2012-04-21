#include "enemy.h"

Enemy::Enemy():life(0),speed(0),armor(0)
{
    m_boundingRect=QRectF(-145,-145,290,290);
}

Enemy::Enemy(int l, int s, int a):life(l),speed(s),armor(a)
{
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    QPixmap ship(":/data/DeathStartar.png");
    painter->drawPixmap(QRect(-145,-145,290,290),ship);
}

QRectF Enemy::boundingRect() const
{
    return m_boundingRect;
}

void Enemy::setBoundingRect(QRectF rect)
{
    m_boundingRect=rect;
}




