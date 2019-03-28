//File : beefomellete.h
#ifndef beefomellete_H
#define beefomellete_H

#include "sideproduct.h"
#include "cowmilk.h"
#include "platypusmilk.h"

class BeefOmellete : public SideProduct{
private:
    static int jumlah; //jumlah beef omellete
public:
    BeefOmellete(); //ctor beef omellete : untuk menambah jumlah beef omellete, menetapkan harga beef omellete
    ~BeefOmellete(); //dtor beef omellete : untuk mengurangi jumlah beef omellete
    static int getJumlah(); //mendapatkan jumlah beef omellete
};

#endif
