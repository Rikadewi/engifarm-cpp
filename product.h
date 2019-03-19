
//File : product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include "renderables.h"

//merupakan turunan dari kelas Renderables
class Product : public Renderables{
protected:
    int harga; //harga dari setiap produk
public:
    int getHarga(); //getter
};
#endif
