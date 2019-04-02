#include "../Header/plachicksoup.h"
#include <iostream>
using namespace std;

int main(){
    PlachickSoup c;
    int jlh = c.getJumlah();
    int price = c.getHarga();
    int id = c.getID();
    cout << "Jumlah plachicksoup = " << jlh << endl;
    cout << "Harga = " << price << endl;
    cout << "ID = " << id << endl;
}