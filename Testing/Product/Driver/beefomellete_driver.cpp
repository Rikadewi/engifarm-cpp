#include "../beefomellete.h"
#include <iostream>
using namespace std;

int main(){
    BeefOmellete b;
    int jlh = b.getJumlah();
    int price = b.getHarga();
    cout << "Jumlah beefomellete = " << jlh << endl;
    cout << "Harga = " << price << endl;
}