
//File : product.h
#ifndef PRODUCT_H
#define PRODUCT_H


class Product{
protected:
    int harga; //harga dari setiap produk
    int id;
public:
    //id 1..6 farmproduct 7..9 sideproduct
    //1 : chickenegg
    //2 : chickenmeat
    //3 : cowmeat
    //4 : cowmilk
    //5 : platypusegg
    //6 : platypusmilk
    //7 : beefomellete
    //8 : plachicksoup
    //9 : platycowpancake
    int getHarga(); //getter harga
    int getID(); //getter id
};
#endif
