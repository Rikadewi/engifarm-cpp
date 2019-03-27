#include "truck.h"

char Truck::render(){

}

bool Truck::isAvailable(){
    return (tick==0);
}

void Truck::updateTick(){
    if(tick>0){
        tick--;
    }
}