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
char ChickenJago::render(){
	return 'J';
}