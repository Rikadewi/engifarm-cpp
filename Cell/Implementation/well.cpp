#include "../Header/well.h"

int Well::render(){
    return 19;
}

void Well::updateCell(UpdateType){
    //do nothing
}

void Well::interactCell(){
    engi->interactWell();
}