#include "../chickenegg.h"

int ChickenEgg::jumlah = 0;

ChickenEgg::ChickenEgg(){
    jumlah+=1;
    harga=3000;
}
    
ChickenEgg::~ChickenEgg(){
    jumlah-=1;
}

int ChickenEgg::getJumlah(){
    return jumlah;
}