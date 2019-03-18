//File: livingthings.h
#ifndef __LIVINGTHINGS_H__
#define __LIVINGTHINGS_H__

#include "renderables.h"

class LivingThings : public Renderables {
    public:
        virtual void Move();
    protected:
      List <char> lookAround;

};

#endif
