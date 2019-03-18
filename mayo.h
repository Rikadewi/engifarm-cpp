//File : mayo.h
#ifndef mayo_H
#define mayo_H

#include "sideproduct.h"

class Mayo : public SideProduct{
private:
    static int jumlah;
public:
    Mayo();
    ~Mayo();
    static int getJumlah();
};

#endif
