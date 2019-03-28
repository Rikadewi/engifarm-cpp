#include "../platypusmilk.h"

int PlatypusMilk::jumlah = 0;

PlatypusMilk::PlatypusMilk(){
    jumlah+=1;
    harga=25000;
}
    
PlatypusMilk::~PlatypusMilk(){
    jumlah-=1;
}

int PlatypusMilk::getJumlah(){
    return jumlah;
}