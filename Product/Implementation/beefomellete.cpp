#include "../Header/beefomellete.h"

int BeefOmellete::jumlah = 0;

BeefOmellete::BeefOmellete(){
    jumlah+=1;
    harga=60000;
    id=7;
}
    
BeefOmellete::~BeefOmellete(){
    jumlah-=1;
}

int BeefOmellete::getJumlah(){
    return jumlah;
}