//File : plachicksoup.h
#ifndef plachicksoup_H
#define plachicksoup_H

#include "sideproduct.h"
#include "cowmeat.h"
#include "chickenmeat.h"

//plachicksoup merupakan turunan dari sideproduct
class PlachickSoup : public SideProduct{
private:
    static int jumlah; //jumlah plachick soup
public:
    PlachickSoup(); //ctor plachick soup : untuk menambah jumlah plachick soup,menetapkan harga plachick soup
    ~PlachickSoup(); //dtor plachick soup : untuk mengurangi jumlah plachick soup
    static int getJumlah(); //mendapatkan jumlah plachick soup
};

#endif
