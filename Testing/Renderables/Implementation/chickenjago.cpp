#include "chickenjago.h"

//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
ChickenJago::ChickenJago(){
	FarmAnimal::egg = true;
	FarmAnimal::milk = false;
	FarmAnimal::meat = true;
}
//prosedur Bersuara menuliskan suara ChickenJago ke layar
void ChickenJago::bersuara(){
	cout << "kukuruyuuuuuk" << endl;
}
FarmProduct ChickenJago::kill(){
	ChickenMeat meat;
	return meat;
}
int ChickenJago::render(){
	//return 'J';
}