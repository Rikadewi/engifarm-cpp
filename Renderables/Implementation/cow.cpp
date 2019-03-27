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
FarmProduct Cow::getProduct(){
	if (hasProduct)
	{
		hasProduct = false;
		CowMilk milk;
		return milk;
	}
	else{
		throw "Sapi ini tidak mempunyai produk saat ini";
	}
}
FarmProduct Cow::kill(){
	CowMeat meat;
	return meat;
}
char Cow::render(){
	return 'C';
}