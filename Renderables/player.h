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

class Player : public LivingThings {
    private:
        int water; //menyimpan jumlah air yg dimiliki player
        List <Product> inventory; //tas
        long money; //menyimpang uang dari player
    public:
        Player(); //ctor
        void move(); //berpindah ke cell yang bertipe land, throw "Tidak ada space" jika di sekeliling player tidak ada land
        void talk(); //berbicara dengan hewan, throw "Tidak ada hewan" jika tidak ditemukan hewan di sekeliling player
        void interact(); //interact dengan facility atau egg dan milk producing animal, throw "Tidak bisa interact" jika gagal
        void kill(); //membunuh meat producing animal, throw "Tidak ada hewan untuk dibunuh" jika gagal
        void grow();
        char render();
        void cekPosisi(int, int&, int&); //buat cek sekitar look around, mungkin bs ditaruh di kelas lbh atas kalo dibutuhkan
};

#endif
