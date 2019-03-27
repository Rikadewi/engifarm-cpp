#include "bull.h"

//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
Bull::Bull(){
	FarmAnimal::egg = false;
	FarmAnimal::milk = false;
	FarmAnimal::meat = true;
}
//prosedur Bersuara menuliskan suara Bull ke layar
void Bull::bersuara(){
	cout << "(Manly) Moooo..." << endl;
}
FarmProduct Bull::kill(){
	CowMeat meat;
	return meat;
}
int Bull::render(){
	//return 'B';
}