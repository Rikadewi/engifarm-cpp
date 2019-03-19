//File : chickenmeat.h
#ifndef chickenmeat_H
#define chickenmeat_H

#include "farmproduct.h"

class ChickenMeat : public FarmProduct{
private:
    static int jumlah;
    
public:
    ChickenMeat();
    ~ChickenMeat();
    static int getJumlah();
};

#endif
