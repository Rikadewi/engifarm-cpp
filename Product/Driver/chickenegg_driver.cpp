#include "../Header/chickenegg.h"
#include <iostream>
using namespace std;

int main(){
    ChickenEgg c;
    int jlh = c.getJumlah();
    int price = c.getHarga();
    int id = c.getID();
    cout << "Jumlah ChickenEgg = " << jlh << endl;
    cout << "Harga = " << price << endl;
    cout << "ID = " << id << endl;
}