//File : beefomellete.h
#ifndef beefomellete_H
#define beefomellete_H

#include "sideproduct.h"
#include "cowmilk.h"
#include "platypusmilk.h"

class BeefOmellete : public SideProduct{
private:
    static int jumlah;
public:
    BeefOmellete();
    ~BeefOmellete();
    static int getJumlah();
};

#endif
