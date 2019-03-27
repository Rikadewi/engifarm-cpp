#include "../platypusegg.h"
#include <iostream>
using namespace std;

int main(){
    PlatypusEgg c;
    int jlh = c.getJumlah();
    int price = c.getHarga();
    cout << "Jumlah platypusegg = " << jlh << endl;
    cout << "Harga = " << price << endl;
}