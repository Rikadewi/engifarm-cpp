//File : cowmeat.h
#ifndef cowmeat_H
#define cowmeat_H

#include "farmproduct.h"

//cowmeat merupakan turunan dari farm product
class CowMeat : public FarmProduct{
private:
    static int jumlah; //jumlah cow meat 
public:
    CowMeat(); //ctor cow meat : untuk menambah jumlah cow meat, menetapkan harga chicken meat
    ~CowMeat(); //dtor cow meat : untuk mengurangi jumlah cow meat
    static int getJumlah(); //mendapatkan jumlah cow meat
};

#endif
