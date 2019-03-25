//File: livingthings.h
#ifndef __LIVINGTHINGS_H__
#define __LIVINGTHINGS_H__

#include "../list.h"
#include "renderables.h"

class LivingThings : public Renderables {
    public:
        virtual void Move();
    protected:
        List <char> lookAround(); //diubah jadi method
};

#endif
