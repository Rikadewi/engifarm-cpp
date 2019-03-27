#include "../cowmilk.h"
#include <iostream>
using namespace std;

int main(){
    CowMilk c;
    int jlh = c.getJumlah();
    int price = c.getHarga();
    cout << "Jumlah cowmilk = " << jlh << endl;
    cout << "Harga = " << price << endl;
}