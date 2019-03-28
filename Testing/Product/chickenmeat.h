//File : chickenmeat.h
#ifndef chickenmeat_H
#define chickenmeat_H

#include "farmproduct.h"

class ChickenMeat : public FarmProduct{
private:
    static int jumlah; //jumlah chicken meat 
public:
    ChickenMeat(); //ctor chicken meat : untuk menambah jumlah chicken meat, menetapkan harga chicken meat
    ~ChickenMeat(); //dtor chicken meat : untuk mengurangi jumlah chicken meat
    static int getJumlah(); //mendapatkan jumlah chicken meat
};

#endif
