#ifndef PRODUCT_H
#define PRODUCT_H

class Product{
protected:
    int harga;        
};

class FarmProduct : public Product{
};

class PlatypusEgg : public FarmProduct{
private:
    static int jumlah;
public:
    PlatypusEgg();
    ~PlatypusEgg();
    static int getJumlah();
};

class ChickenEgg : public FarmProduct{
private:
    static int jumlah;
public:
    ChickenEgg();
    ~ChickenEgg();
    static int getJumlah();
};

class PlatypusMilk : public FarmProduct{
private:
    static int jumlah;
public:
    PlatypusMilk();
    ~PlatypusMilk();
    static int getJumlah();
};

class CowMilk : public FarmProduct{
private:
    static int jumlah;
public:
    CowMilk();
    ~CowMilk();
    static int getJumlah();
};

class ChickenMeat : public FarmProduct{
private:
    static int jumlah;
public:
    ChickenMeat();
    ~ChickenMeat();
    static int getJumlah();
};

class CowMeat : public FarmProduct{
private:
    static int jumlah;
public:
    CowMeat();
    ~CowMeat();
    static int getJumlah();
};

class SideProduct : public Product{
};


class Cheese : public SideProduct{
private:
    static int jumlah;
public:
    Cheese(CowMilk);
    Cheese(PlatypusMilk);
    ~Cheese();
    static int getJumlah();
};

class Steak : public SideProduct{
private:
    static int jumlah;
public:
    Steak(CowMeat);
    Steak(ChickenMeat);
    ~Steak();
    static int getJumlah();
};

class Mayo : public SideProduct{
private:
    static int jumlah;
public:
    Mayo(PlatypusEgg);
    Mayo(ChickenEgg);
    ~Mayo();
    static int getJumlah();
};

#endif