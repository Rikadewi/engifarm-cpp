#include "../Header/plachicksoup.h"

int PlachickSoup::jumlah = 0;

PlachickSoup::PlachickSoup(){
    jumlah+=1;
    harga=55000;
    id=8;
}
    
PlachickSoup::~PlachickSoup(){
    jumlah-=1;
}

int PlachickSoup::getJumlah(){
    return jumlah;
}