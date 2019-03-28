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
FarmProduct Cow::getProduct(bool isKill){
	if (isKill){
		CowMeat meat;
		return meat;
	}
	else{
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
}
int Cow::render(){
	if (hungry)
		return 5;
	else
	{
		return 6;
	}
	
}