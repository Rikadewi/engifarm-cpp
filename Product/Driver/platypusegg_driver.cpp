#include "../Header/platypusegg.h"
#include <iostream>
using namespace std;

int main(){
    PlatypusEgg c;
    int jlh = c.getJumlah();
    int price = c.getHarga();
    int id = c.getID();
    cout << "Jumlah platypusegg = " << jlh << endl;
    cout << "Harga = " << price << endl;
    cout << "ID = " << id << endl;
}