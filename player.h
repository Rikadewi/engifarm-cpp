//File: player.h
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "livingthings.h"
#include "product.h"
#include "list.h"

class Player : public LivingThings {
    private:
        int water;
        List <Product> inventory;
        long money;
    public:
        void talk();
        void interact();
        void kill();
        void grow();
        char render();
};

#endif
