//File : platycowpancake.h
#ifndef platycowpancake_H
#define platycowpancake_H

#include "sideproduct.h"

//platycow pancake merupakan turunan dari sideproduct
class PlatycowPancake : public SideProduct{
private:
    static int jumlah; //jumlah platycow pancake
public:
    PlatycowPancake(); //ctor platycow pancake : untuk menambah jumlah platycow pancake, menetapkan harga platycow pancake
    ~PlatycowPancake(); //dtor platycow pancake : untuk mengurangi jumlah platycow pancake
    static int getJumlah(); //mendapatkan jumlah platycow pancake
};

#endif
