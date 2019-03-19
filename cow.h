// File: cow.h
#ifndef cow_H
#define cow_H

#include "farmanimal.h"

class Cow : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
	Cow();
	//prosedur Bersuara menuliskan suara Cow ke layar
	void bersuara();
	// static const bool isEgg();
	// static const bool isMilk();
	// static const bool isMeat();
	char render();
};

#endif
