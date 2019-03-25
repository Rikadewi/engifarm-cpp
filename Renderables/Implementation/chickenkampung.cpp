#include "chickenkampung.h"

ChickenKampung::ChickenKampung(){
	FarmAnimal::egg = true;
	FarmAnimal::milk = false;
	FarmAnimal::meat = true;
}
void ChickenKampung::bersuara(){
	cout << "pok pok petoook" << endl;
}
char ChickenKampung::render(){
	return 'K';
}