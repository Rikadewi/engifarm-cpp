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

void Truck::updateTick(){
    if(ready>0){
        ready--;
    }
}
