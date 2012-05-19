#ifndef GEN_H
#define GEN_H
#include <stdint.h>

class Gen
{
private:
    uint32_t genom;
public:
    Gen()
    {
        genom=0;
    }


    inline void resetGen()
    {
        genom=0;
    }

    inline void setTowerType(unsigned int type)
    {
        type=type<<24;
        genom=genom|type;
    }

    inline void setTowerX(unsigned int X)
    {
        X=X<<12;
        genom=genom|X;
    }
    inline void setTowerY(unsigned int Y)
    {
        genom=genom|Y;
    }

    inline int getTowerType()//2bits
    {
        return genom>>24;
    }

    int getTowerX()//12bits
    {
        uint32_t m=0;
        m = ~0;
        m = m << 2;
        m = ~m;
        m = m << 24;
        m = ~m;

        uint32_t X=genom&m;

        X=X>>12;
        return X;

    }
    int getTowerY()//12bits
    {
        uint32_t m=0;
        m = ~0;
        m = m << 14;
        m = ~m;
        m = m << 12;
        m = ~m;

        uint32_t X=genom&m;
        return X;
    }

    uint32_t getGenom()
    {
        return genom;
    }
};

#endif
