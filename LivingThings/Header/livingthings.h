//File: livingthings.h
#ifndef __LIVINGTHINGS_H__
#define __LIVINGTHINGS_H__

#include "../../List/list.h"

class LivingThings {
    public:
        virtual void move() = 0;
        int getX();
        int getY();
        void setX(int);
        void setY(int);
    private:
        //urutan: utara, timur, selatan, barat
        int posisiX;
        int posisiY;
};

#endif
