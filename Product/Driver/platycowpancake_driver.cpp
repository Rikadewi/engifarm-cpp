#include "../Header/platycowpancake.h"
#include <iostream>
using namespace std;

int main(){
    PlatycowPancake p;
    int jlh = p.getJumlah();
    int price = p.getHarga();
    int id = p.getID();
    cout << "Jumlah platycowpancake = " << jlh << endl;
    cout << "Harga = " << price << endl;
    cout << "ID = " << id << endl;
}