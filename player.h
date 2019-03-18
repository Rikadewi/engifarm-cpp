//File: player.h
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "livingthings.h"
#include "product.h"

class Player: public LivingThings {
    public:
        int water;
        List <Product> inventory;
        long money;
    private:
        void talk();
        void interact();
        void kill();
        void grow();
        void render();
};

#endif 
