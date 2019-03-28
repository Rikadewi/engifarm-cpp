#include "../Header/platycowpancake.h"

int PlatycowPancake::jumlah = 0;

PlatycowPancake::PlatycowPancake(){
    jumlah+=1;
    harga=30000;
    id=9;
}
    
PlatycowPancake::~PlatycowPancake(){
    jumlah-=1;
}

int PlatycowPancake::getJumlah(){
    return jumlah;
}