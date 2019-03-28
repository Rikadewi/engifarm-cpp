#include "../Header/facility.h"

FacilityType Facility::getType(){
    return type;
}

void Facility::setType(FacilityType type){
    this->type = type;
}

FarmAnimal* Facility::getAnimal(){
    return NULL;
}

void Facility::setAnimal(FarmAnimal* animal){
    throw "Can't set Facility";
}