#include "../Header/platypusmilk.h"
#include <iostream>
using namespace std;

int main(){
    PlatypusMilk p;
    int jlh = p.getJumlah();
    int price = p.getHarga();
    int id = p.getID();
    cout << "Jumlah platypusmilk = " << jlh << endl;
    cout << "Harga = " << price << endl;
    cout << "ID = " << id << endl;
}