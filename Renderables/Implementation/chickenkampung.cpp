#include "chickenkampung.h"

ChickenKampung::ChickenKampung(){
	FarmAnimal::egg = true;
	FarmAnimal::milk = false;
	FarmAnimal::meat = true;
}
void ChickenKampung::bersuara(){
	cout << "pok pok petoook" << endl;
}
FarmProduct ChickenKampung::getProduct(){
	if (hasProduct){
		ChickenEgg egg;
		return egg;
	}
	else
	{
		throw "ayam kampung ini tidak memiliki produk saat ini";
	}
	
}
FarmProduct ChickenKampung::kill(){
	ChickenMeat meat;
	return meat;
}
int ChickenKampung::render(){
	//return 'K';
}