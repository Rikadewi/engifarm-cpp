//File : steak.h
#ifndef steak_H
#define steak_H

#include "sideproduct.h"
#include "cowmeat.h"
#include "chickenmeat.h"

class Steak : public SideProduct{
private:
    static int jumlah;
public:
    Steak(CowMeat);
    Steak(ChickenMeat);
    ~Steak();
    static int getJumlah();
};

#endif
