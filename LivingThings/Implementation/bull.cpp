#include "../bull.h"

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
FarmProduct Bull::getProduct(bool isKill){
	if (isKill){
		CowMeat meat;
		return meat;
	}
	else
		throw "Bull tidak memiliki susu";
	
}
int Bull::render(){
	if (hungry)
		return 7;
	else
		return 8;
	
}