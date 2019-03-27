// File: chickenjago.h
#ifndef chickenjago_H
#define chickenjago_H

#include "farmanimal.h"
#include "chickenmeat.h"

class ChickenJago : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
	ChickenJago();
	//prosedur Bersuara menuliskan suara ChickenJago ke layar
	void bersuara();
	FarmProduct kill();
	int render();
};

#endif
