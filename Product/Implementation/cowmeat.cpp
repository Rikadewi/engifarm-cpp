#include "../Header/cowmeat.h"

int CowMeat::jumlah = 0;

CowMeat::CowMeat(){
    jumlah+=1;
    harga=45000;
    id=3;
}
    
CowMeat::~CowMeat(){
    jumlah-=1;
}

int CowMeat::getJumlah(){
    return jumlah;
}