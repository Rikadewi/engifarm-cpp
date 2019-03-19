// File: platypus.h
#ifndef platypus_H
#define platypus_H

#include "farmanimal.h"

class Platypus : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
	Platypus();
	//prosedur Bersuara menuliskan suara Platypus ke layar
	void bersuara();
	// static const bool isEgg();
	// static const bool isMilk();
	// static const bool isMeat();
	char render();
};

#endif
