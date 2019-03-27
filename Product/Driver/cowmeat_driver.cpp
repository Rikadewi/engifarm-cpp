#include "../cowmeat.h"
#include <iostream>
using namespace std;

int main(){
    CowMeat c;
    int jlh = c.getJumlah();
    int price = c.getHarga();
    cout << "Jumlah cowmeat = " << jlh << endl;
    cout << "Harga = " << price << endl;
}