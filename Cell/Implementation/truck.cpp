#include "../truck.h"

int Truck::render(){
    return 21;
}

bool Truck::isAvailable(){
    return (tick==0);
}

void Truck::updateTick(){
    if(tick>0){
        tick--;
    }
}