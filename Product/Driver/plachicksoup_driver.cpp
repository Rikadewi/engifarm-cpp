#include "../plachicksoup.h"
#include <iostream>
using namespace std;

int main(){
    PlachickSoup c;
    int jlh = c.getJumlah();
    int price = c.getHarga();
    cout << "Jumlah plachicksoup = " << jlh << endl;
    cout << "Harga = " << price << endl;
}