//File: player.h
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "livingthings.h"
#include "../Product/product.h"
#include "../list.h"
#define DEFWATER 10
#define MAXWATER 20
#define DEFMONEY 100
#define MAXMONEY 200
#define MAXBAG 10

//hapus ntar, untuk kepentingan development
#define charLand 'L'
#define charLandBerumput 'R'
#define charBarn ''
#define COL 10

class Player : public LivingThings {
    private:
        int water; //menyimpan jumlah air yg dimiliki player
        List <Product> inventory; //tas
        long money; //menyimpang uang dari player
    public:
        Player(); //ctor
        void move(); //berpindah ke cell yang bertipe land, throw "Tidak ada space" jika di sekeliling player tidak ada land
        void talk(); //throwing
        void interact();
        void kill();
        void grow();
        char render();
};

#endif0
