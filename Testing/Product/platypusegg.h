//File : platypusegg.h
#ifndef platypusegg_H
#define platypusegg_H

#include "farmproduct.h"

//platypusegg merupakan turunan dari farmproduct
class PlatypusEgg : public FarmProduct{
private:
    static int jumlah; //jumlah platypus egg
public:
    PlatypusEgg(); //ctor platypus egg : untuk menambah jumlah platypus egg, menetapkan harga platypus egg
    ~PlatypusEgg(); //dtor platypus egg : untuk mengurangi jumlah platypus egg
    static int getJumlah(); //mendapatkan jumlah platypus egg
};

#endif
