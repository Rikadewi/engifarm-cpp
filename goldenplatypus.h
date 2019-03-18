// File: goldenplatypus.h
#ifndef goldenplatypus_H
#define goldenplatypus_H

#include "farmanimal.h"

class GoldenPlatypus : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
	GoldenPlatypus();
	//prosedur Bersuara menuliskan suara GoldenPlatypus ke layar
	void Bersuara();
	static const bool isEgg();
	static const bool isMilk();
	static const bool isMeat();
	void render();
};

#endif
