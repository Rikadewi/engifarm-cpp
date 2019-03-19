//File : platypusmilk.h
#ifndef platypusmilk_H
#define platypusmilk_H

#include "farmproduct.h"

//platypus milk merupakan turunan dari farm product
class PlatypusMilk : public FarmProduct{
private:
    static int jumlah; //jumlah platypus milk
public:
    PlatypusMilk(); //ctor platypus milk : untuk menambah jumlah platypus milk, menetapkan harga platypus milk
    ~PlatypusMilk(); //dtor platypus milk : untuk mengurangi jumlah platypus egg
    static int getJumlah(); //mendapatkan jumlah platypus milk yang ada
};

#endif
