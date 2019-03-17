#ifndef CELL_H
#define CELL_H
#include "product.h"

class Cell : Renderables{
public:
    virtual void draw();
};

class Land : public Cell {
};

class Coop : public Land{
public:
    void draw();
};
//static max coop
//1 coop mau berapa
//

class Barn : public Land{
public:
    void draw();
};

class GrassLand : public Land{
public:
    void draw();  
};

class Facility : public Cell{
};

class Well : public Facility{
public:
    void draw();
    void fillWater();
};

class Mixer : public Facility{
public:
    void draw();
    void mix(ChickenEgg);
    void mix(PlatypusEgg);
    void mix(ChickenMeat);
    void mix(CowMeat);
    void mix(CowMilk);
    void mix(PlatypusMilk);
};

class Truck : public Facility{
public:
    void draw();

};


#endif