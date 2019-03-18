//File : platypusegg.h
#ifndef platypusegg_H
#define platypusegg_H

#include "farmproduct.h"

class PlatypusEgg : public FarmProduct{
private:
    static int jumlah;
public:
    PlatypusEgg();
    ~PlatypusEgg();
    static int getJumlah();
};

#endif
