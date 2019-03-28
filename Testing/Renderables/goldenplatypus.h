// File: goldenplatypus.h
#ifndef goldenplatypus_H
#define goldenplatypus_H

#include "../Product/platypusegg.h"
#include "../Product/platypusmilk.h"
#include "../Product/farmproduct.h"
#include "farmanimal.h"

class GoldenPlatypus : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
	GoldenPlatypus();
	//prosedur Bersuara menuliskan suara GoldenPlatypus ke layar
	void bersuara();
	FarmProduct getProduct();
	int render()
	;
};

#endif
