//File: livingthings.h
#ifndef __LIVINGTHINGS_H__
#define __LIVINGTHINGS_H__

#include "../list.h"
#include "renderables.h"

class LivingThings : public Renderables {
    public:
        virtual void move() = 0;
    protected:
        //urutan: utara, timur, selatan, barat
        List <int> lookAround(); //diubah jadi method
        
};

#endif
