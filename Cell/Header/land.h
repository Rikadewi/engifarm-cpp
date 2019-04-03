//File : land.h
#ifndef land_H
#define land_H

#include "cell.h"
#include "../../LivingThings/Header/farmanimal.h"

enum LandType {barn, coop, grassLand};

class Land : public Cell {
    private:
        bool rumput; 
        FarmAnimal* animal;
        LandType type;
    public:
        Land ();
        Land (bool rumput, FarmAnimal* animal, LandType type);
        int render();  //mengembalikan char yang akan diprint
        bool isRumput(); 
        void setRumput(bool); //set isRumput menjadi true jika merupakan grassland, false ketika dimakan animal
        LandType getType();
        void setType(LandType);
        FarmAnimal* getAnimal();
        void setAnimal(FarmAnimal*);
        void updateCell();


};

#endif
