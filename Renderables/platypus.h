// File: platypus.h
#ifndef platypus_H
#define platypus_H

#include "farmanimal.h"
#include "../Product/farmproduct.h"
#include "../Product/platypusegg.h"
#include "../Product/platypusmilk.h"

class Platypus : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
	Platypus();
	//prosedur Bersuara menuliskan suara Platypus ke layar
	void bersuara();
	FarmProduct getProduct();
	int render();
};

#endif
