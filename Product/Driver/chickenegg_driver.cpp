#include "../chickenegg.h"
#include <iostream>
using namespace std;

int main(){
    ChickenEgg c;
    int jlh = c.getJumlah();
    int price = c.getHarga();
    cout << "Jumlah ChickenEgg = " << jlh << endl;
    cout << "Harga = " << price << endl;
}