#include "../Header/beefomellete.h"
#include <iostream>
using namespace std;

int main(){
    BeefOmellete b;
    int jlh = b.getJumlah();
    int price = b.getHarga();
    int id = b.getID();
    cout << "Jumlah beefomellete = " << jlh << endl;
    cout << "Harga = " << price << endl;
    cout << "ID = " << id << endl;
}