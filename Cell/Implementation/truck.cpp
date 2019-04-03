#include "../Header/truck.h"

void Truck::setNotReady(){
    ready = MAXREADY;
}

int Truck::render(){
    return 21;
}

bool Truck::isAvailable(){
    return (ready==0);
}

void Truck::updateCell(UpdateType type){
    if (type == readyTruck){
        if(ready>0){
            ready--;
        }
    }
}

void Truck::interactCell(){
    if(isAvailable()){
        engi->interactTruck();
        setNotReady();
    }else{
        throw "Truck tidak ada";
    }
}