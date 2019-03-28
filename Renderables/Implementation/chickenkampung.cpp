#include "chickenkampung.h"

ChickenKampung::ChickenKampung(){
	FarmAnimal::egg = true;
	FarmAnimal::milk = false;
	FarmAnimal::meat = true;
}
void ChickenKampung::bersuara(){
	cout << "pok pok petoook" << endl;
}
FarmProduct ChickenKampung::getProduct(bool isKill){
	if (isKill){
		ChickenMeat meat;
		return meat;
	}
	else{
		if (hasProduct){
			ChickenEgg egg;
			return egg;
		}
		else
			throw "ayam kampung ini tidak memiliki produk saat ini";
	}
}
int ChickenKampung::render(){
	if (hungry)
		return 1;
	else
		return 2;
	
}