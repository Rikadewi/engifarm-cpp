#include "../Header/chickenmeat.h"

int ChickenMeat::jumlah = 0;

ChickenMeat::ChickenMeat(){
    jumlah+=1;
    harga=17000;
    id=2;
}
    
ChickenMeat::~ChickenMeat(){
    jumlah-=1;
}

int ChickenMeat::getJumlah(){
    return jumlah;
}