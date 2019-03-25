#include "goldenplatypus.h"

GoldenPlatypus::GoldenPlatypus(){
	FarmAnimal::egg = true;
	FarmAnimal::milk = true;
	FarmAnimal::meat = false;
}

//prosedur Bersuara menuliskan suara GoldenPlatypus ke layar
void GoldenPlatypus::bersuara(){
	cout << "krrrrrrr..." << endl;
}

char GoldenPlatypus::render(){
	return 'G';
}