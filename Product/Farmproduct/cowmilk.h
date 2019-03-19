//File : cowmilk.h
#ifndef cowmilk_H
#define cowmilk_H

#include "farmproduct.h"

class CowMilk : public FarmProduct{
private:
    static int jumlah;
public:
    CowMilk();
    ~CowMilk();
    static int getJumlah();
};

#endif
