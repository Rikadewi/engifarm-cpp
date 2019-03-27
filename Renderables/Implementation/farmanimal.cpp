#include "farmanimal.h"

#define default_living_time 10

int FarmAnimal::jumlah = 0;

//konstruktor FarmAnimal, mengeset hungry dan hasProduct menjadi false, living_time mejadi default, menambah static int jumlah
FarmAnimal::FarmAnimal(){
	hungry = false;
	hasProduct = false;
	living_time = default_living_time;
	jumlah++;
}
//destruktor FarmAnimal, mengurangi static int jumlah
FarmAnimal::~FarmAnimal(){
	jumlah--;
}
//prosedur makan mengembalikan living_time menjadi default
void FarmAnimal::makan(){
	living_time = default_living_time;
	hasProduct = true;
}
//prosedur update dipanggil setiap tick
void FarmAnimal::update(){
	if (hungry){
		living_time--;
		if (living_time == 0){
			delete this;
		}
		else
			Move();
	}
}
//prosedur virtual void makeHungry
void FarmAnimal::makeHungry(){
	hungry = true;
}
//fungsi boolean isHungry mengembalikan true jika atribut hungry bernilai true
bool FarmAnimal::isHungry(){
	return hungry;
}
bool FarmAnimal::is_safe_to_move(int x){
	List <int> around = LivingThings::lookAround();
	if ((around.get(x)<=12)||(around.get(x)>=19)){
		return false;
	}
	else
	{
		return true;
	}
	
}
void FarmAnimal::Move(){
	int direction = rand() % 4;
	if (is_safe_to_move(direction)){
		switch (direction){
			case 0: //utara
				int y = Renderables::getY();
				Renderables::setY(y-1);
				break;
			case 1: //timur
				int x = Renderables::getX();
				Renderables::setX(x+1);
				break;
			case 2: //selatan
				int y = Renderables::getY();
				Renderables::setY(y+1);
				break;
			case 3: //barat
				int x = Renderables::getX();
				Renderables::setX(x-1);
				break;
		}
	}
}

//deklarasi fungsi pure virtual
bool FarmAnimal::isEgg(){
	return egg;
}
bool FarmAnimal::isMilk(){
	return milk;
}
bool FarmAnimal::isMeat(){
	return meat;
}
int FarmAnimal::getJumlah(){
	return jumlah;
}