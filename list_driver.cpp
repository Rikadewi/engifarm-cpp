/*Implementasi Kelas List
Gardahadi / 13517144 */
#include "list.h"
#include <iostream>
using namespace std;
//Ctor
int main() {
    List<int> IntList;
    List<char> CharList(3);
    for(int i=1; i<=10; i++){
        IntList.add(i);
    }
    CharList.add('a');
    CharList.add('b');
    CharList.add('c');
    for(int i=IntList.getFirstIdx(); i<=IntList.getLastIdx(); i++){
        cout<<IntList.getElmt(i)<<endl;
    }
    int X;
    IntList.remove(3,&X);
    cout << "Setelah menghilangkan 3" << endl;
    for(int i=IntList.getFirstIdx(); i<=IntList.getLastIdx(); i++){
        cout<<IntList.getElmt(i)<<endl;
    }
    cout << "Object to delete : " << X << endl;
}