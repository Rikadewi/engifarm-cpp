#include "../platycowpancake.h"
#include <iostream>
using namespace std;

int main(){
    PlatycowPancake p;
    int jlh = p.getJumlah();
    int price = p.getHarga();
    cout << "Jumlah platycowpancake = " << jlh << endl;
    cout << "Harga = " << price << endl;
}