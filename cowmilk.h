//File : cowmilk.h
#ifndef cowmilk_H
#define cowmilk_H

#include "farmproduct.h"

//cowmilk merupakan turunan dari farm product
class CowMilk : public FarmProduct{
private:
    static int jumlah; //jumlah cow milk
public:
    CowMilk(); //ctor cow milk : untuk menambah jumlah cow milk, menetapkan harga cow milk
    ~CowMilk(); //dtor cow milk : untuk mengurangi jumlah cow milk
    static int getJumlah(); //mendapatkan jumlah cow milk
};

#endif
