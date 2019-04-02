#include "../Header/cowmilk.h"
#include <iostream>
using namespace std;

int main(){
    CowMilk c;
    int jlh = c.getJumlah();
    int price = c.getHarga();
    int id = c.getID();
    cout << "Jumlah cowmilk = " << jlh << endl;
    cout << "Harga = " << price << endl;
    cout << "ID = " << id << endl;
}