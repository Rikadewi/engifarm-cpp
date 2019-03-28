#include "../chickenmeat.h"
#include <iostream>
using namespace std;

int main(){
    ChickenMeat c;
    int jlh = c.getJumlah();
    int price = c.getHarga();
    cout << "Jumlah chickenmeat = " << jlh << endl;
    cout << "Harga = " << price << endl;
}