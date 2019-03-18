//File : cheese.h
#ifndef cheese_H
#define cheese_H

#include "sideproduct.h"
#include "cowmilk.h"
#include "platypusmilk.h"

class Cheese : public SideProduct{
private:
    static int jumlah;
public:
    Cheese();
    ~Cheese();
    static int getJumlah();
};

#endif
