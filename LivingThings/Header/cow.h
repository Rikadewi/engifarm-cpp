// File: cow.h
#ifndef cow_H
#define cow_H

#include "farmanimal.h"
#include "../Product/cowmilk.h"
#include "../Product/cowmeat.h"

class Cow : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
	Cow();
	//prosedur Bersuara menuliskan suara Cow ke layar
	void bersuara();
	FarmProduct getProduct();
	FarmProduct kill();
	int render();
};

#endif
