// File: chickenkampung.h
#ifndef chickenkampung_H
#define chickenkampung_H

#include "farmanimal.h"

class ChickenKampung : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
	ChickenKampung();
	//prosedur Bersuara menuliskan suara ChickenKampung ke layar
	void Bersuara();
	// static const bool isEgg();
	// static const bool isMilk();
	// static const bool isMeat();
	char render();
};

#endif
