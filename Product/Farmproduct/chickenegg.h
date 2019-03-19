//File : chickenegg.h
#ifndef chickenegg_H
#define chickenegg_H

#include "farmproduct.h"

class ChickenEgg : public FarmProduct{
private:
    static int jumlah;
public:
    ChickenEgg();
    ~ChickenEgg();
    static int getJumlah();
};

#endif
