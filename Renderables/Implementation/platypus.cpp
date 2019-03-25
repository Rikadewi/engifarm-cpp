#include "platypus.h"

Platypus::Platypus(){
	FarmAnimal::egg = true;
	FarmAnimal::milk = true;
	FarmAnimal::meat = false;
}

//prosedur Bersuara menuliskan suara Platypus ke layar
void Platypus::bersuara(){
	cout << "krrrrrrr..." << endl;
}

char Platypus::render(){
	return 'P';
}