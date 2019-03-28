// File: bull.h
#ifndef bull_H
#define bull_H

#include "farmanimal.h"
#include "../../Product/Header/cowmeat.h"

class Bull : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
	Bull();
	//prosedur Bersuara menuliskan suara Bull ke layar
	void bersuara();
	FarmProduct kill();
	FarmProduct getProduct(bool);
	int render();
};

#endif
