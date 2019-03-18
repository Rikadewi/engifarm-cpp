//File : plachicksoup.h
#ifndef plachicksoup_H
#define plachicksoup_H

#include "sideproduct.h"
#include "cowmeat.h"
#include "chickenmeat.h"

class PlachickSoup : public SideProduct{
private:
    static int jumlah;
public:
    PlachickSoup();
    ~PlachickSoup();
    static int getJumlah();
};

#endif
