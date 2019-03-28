#include "../Header/platypusmilk.h"

int PlatypusMilk::jumlah = 0;

PlatypusMilk::PlatypusMilk(){
    jumlah+=1;
    harga=25000;
    id=6;
}
    
PlatypusMilk::~PlatypusMilk(){
    jumlah-=1;
}

int PlatypusMilk::getJumlah(){
    return jumlah;
}