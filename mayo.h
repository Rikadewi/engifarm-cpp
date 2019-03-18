//File : mayo.h
#ifndef mayo_H
#define mayo_H

#include "sideproduct.h"
#include "platypusegg.h"
#include "chickenegg.h"

class Mayo : public SideProduct{
private:
    static int jumlah;
public:
    Mayo(PlatypusEgg);
    Mayo(ChickenEgg);
    ~Mayo();
    static int getJumlah();
};

#endif
