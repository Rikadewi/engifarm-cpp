#include "cow.h"

Cow::Cow(){
	FarmAnimal::egg = false;
	FarmAnimal::milk = true;
	FarmAnimal::meat = true;
}

//prosedur Bersuara menuliskan suara Cow ke layar
void Cow::bersuara(){
	cout << "Moooo..." << endl;
}

char Cow::render(){
	return 'C';
}