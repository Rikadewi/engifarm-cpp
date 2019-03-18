//File : cowmeat.h
#ifndef cowmeat_H
#define cowmeat_H

#include "farmproduct.h"

class CowMeat : public FarmProduct{
private:
    static int jumlah;
public:
    CowMeat();
    ~CowMeat();
    static int getJumlah();
};

#endif
