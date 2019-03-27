#include "../platycowpancake.h"

int PlatycowPancake::jumlah = 0;

PlatycowPancake::PlatycowPancake(){
    jumlah+=1;
    harga=30000;
}
    
PlatycowPancake::~PlatycowPancake(){
    jumlah-=1;
}

int PlatycowPancake::getJumlah(){
    return jumlah;
}