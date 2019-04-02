#include "../Header/chickenmeat.h"
#include <iostream>
using namespace std;

int main(){
    ChickenMeat c;
    int jlh = c.getJumlah();
    int price = c.getHarga();
    int id = c.getID();
    cout << "Jumlah chickenmeat = " << jlh << endl;
    cout << "Harga = " << price << endl;
    cout << "ID = " << id << endl;
}