// File: bull.h
#ifndef bull_H
#define bull_H

#include "farmanimal.h"

class Bull : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
	Bull();
	//prosedur Bersuara menuliskan suara Bull ke layar
	void Bersuara();
	/*static const bool isEgg();
	static const bool isMilk();
	static const bool isMeat();*/
	char render();
};

#endif
