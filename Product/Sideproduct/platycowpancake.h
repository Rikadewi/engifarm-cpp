//File : platycowpancake.h
#ifndef platycowpancake_H
#define platycowpancake_H

#include "sideproduct.h"
class PlatycowPancake : public SideProduct{
private:
    static int jumlah;
public:
    PlatycowPancake();
    ~PlatycowPancake();
    static int getJumlah();
};

#endif
