//File : land.h
#ifndef land_H
#define land_H

#include "cell.h"

enum LandType {}
class Land : public Cell {
    private:
        bool rumput; 
        FarmAnimal animal;
    public:
        int render();  //mengembalikan char yang akan diprint
        bool isRumput(); 
        void setRumput(bool); //set isRumput menjadi true jika merupakan grassland, false ketika dimakan animal

};

#endif
