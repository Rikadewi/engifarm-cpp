#include "../Header/platypusegg.h"

int PlatypusEgg::jumlah = 0;

PlatypusEgg::PlatypusEgg(){
    jumlah+=1;
    harga=10000;
    id=5;
}
    
PlatypusEgg::~PlatypusEgg(){
    jumlah-=1;
}

int PlatypusEgg::getJumlah(){
    return jumlah;
}