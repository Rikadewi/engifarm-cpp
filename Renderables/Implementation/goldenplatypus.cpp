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
FarmProduct GoldenPlatypus::getProduct(){
	if (hasProduct){
		hasProduct = false;
		int x = rand() % 2;
		if (x == 0){
			PlatypusMilk milk;
			return milk;
		}
		else{
			PlatypusEgg egg;
			return egg;
		}
	}
	else{
		throw "Platypus ini tidak mempunyai produk saat ini";
	}
}
int GoldenPlatypus::render(){
	//return 'G';
}