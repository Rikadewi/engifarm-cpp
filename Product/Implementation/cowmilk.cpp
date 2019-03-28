#include "../Header/cowmilk.h"

int CowMilk::jumlah = 0;

CowMilk::CowMilk(){
    jumlah+=1;
    harga=15000;
    id=4;
}
    
CowMilk::~CowMilk(){
    jumlah-=1;
}

int CowMilk::getJumlah(){
    return jumlah;
}