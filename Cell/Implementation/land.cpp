#include "../Header/land.h"

Land::Land(bool rumput, FarmAnimal* animal, LandType type){
    this->rumput = rumput;
    this->animal = animal;
    this->type = type;
}

int Land::render(){
    if(type == barn){
        if(isRumput()){
            return 14;
        }else{
            return 13;
        }
    }

    if(type == coop){
        if(isRumput()){
            return 16;
        }else{
            return 15;
        }
    }

    if(type == grassLand){
        if(isRumput()){
            return 18;
        }else{
            return 17;
        }
    }
}

bool Land::isRumput(){
    return rumput;
}

void Land::setRumput(bool b){
    rumput = b;
}

LandType Land::getType(){
    return type;
}

void Land::setType(LandType type){
    this->type = type;
}

FarmAnimal* Land::getAnimal(){
    return animal;
}

void Land::setAnimal(FarmAnimal* animal){
    this->animal = animal;
}