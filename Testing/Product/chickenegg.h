//File : chickenegg.h
#ifndef chickenegg_H
#define chickenegg_H

#include "farmproduct.h"

class ChickenEgg : public FarmProduct{
private:
    static int jumlah; //jumlah chicken egg 
public:
    ChickenEgg(); //ctor chicken egg : untuk menambah jumlah chicken egg, menetapkan harga chicken egg
    ~ChickenEgg(); //dtor chicken egg : untuk mengurangi jumlah chicken egg
    static int getJumlah(); //mendapatkan jumlah chicken egg
};

#endif
