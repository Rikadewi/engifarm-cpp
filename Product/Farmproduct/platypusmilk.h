//File : platypusmilk.h
#ifndef platypusmilk_H
#define platypusmilk_H

#include "farmproduct.h"

class PlatypusMilk : public FarmProduct{
private:
    static int jumlah;
public:
    PlatypusMilk();
    ~PlatypusMilk();
    static int getJumlah();
};

#endif
