//File: player.h
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "livingthings.h"
#include "../Product/product.h"
#include "farmanimal.h"
#include "../list.h"
#include "truck.h"
#include "facility.h"
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
        //ctor
        Player(); 
        void move(); //berpindah ke cell yang bertipe land, throw "Tidak ada space" jika di sekeliling player tidak ada land
        
        //menerima input Farm Animal
        //mencetak di layar suara animal tersebut
        void talk(FarmAnimal& F); 
        
        //menerima input facility (mixer dan well)
        //throw "Bukan mixer dan well" jika tidak ada
        //berinteraksi dengan well menambah water, jika melebihi kapasitas maka air tidak bertambah
        //mixer
        void interact(Facility& F); 
        
        //menerima input truck
        //berinteraksi dengan truck menjual semua inventory, throw "Truck tidak ada" jika truck belum available
        //hasil penjualan akan ditambahkan ke money
        //jika kapasitas money sudah penuh, maka akan ditambahkan hingga MAXMONEY
        void interact(Truck& T); 

        //menerima input Farm Animal
        //berinteraksi dengan milk dan egg producing animal
        //throw "Tidak bisa berinteraksi dengan meat producing animal" jika berinteraksi dengan meat producing animal
        //jika animal tidak lapar, akan mendapatkan prodcut
        //throw exception jika animal lapar
        //mendapatkan product jika inventory masih cukup
        //throw "Inventory penuh" jika inventory penuh
        void interact(FarmAnimal& F); 
        
        //menerima input Farm Animal
        //jika animal tidak lapar, akan mendapatkan prodcut
        //throw exception jika animal lapar
        //throw "Bukan meat producing animal" jika input bukan meat producing animal
        //throw "Inventory penuh" jika inventory penuh
        void kill(FarmAnimal& F); 

        //mengurangi jumlah water jika water > 0
        //throw "Air tidak cukup" jika water 
        void grow();

        //mengembalikan 22
        int render();
        void cekPosisi(int, int&, int&); //buat cek sekitar look around, mungkin bs ditaruh di kelas lbh atas kalo dibutuhkan
};

#endif
