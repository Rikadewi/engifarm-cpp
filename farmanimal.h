// File: farmanimal.h
#ifndef FARMANIMAL_H
#define FARMANIMAL_H

#include "livingthings.h"

class FarmAnimal : public LivingThings {
protected:
	bool hungry; //variabel penanda bahwa hewan lapar
	static const bool egg; //menandakan jenis hewan penghasil telur
	static const bool milk; //menandakan jenis hewan penghasil susu
	static const bool meat; //menandakan jenis hewan penghasil daging
	int living_time; //variabel penanda tick yang dimiliki sebelum hewan mati kelaparan
public:
	//prosedur makan mengembalikan living_time menjadi default
	void makan();
	//prosedur update dipanggil setiap tick
	void update();
	//prosedur virtual void makeHungry
	virtual void makeHungry() = 0;
	//fungsi boolean isHungry mengembalikan true jika atribut hungry bernilai true
	bool isHungry();
	//deklarasi fungsi pure virtual
	virtual void Bersuara() = 0;
	virtual bool isEgg() = 0;
	virtual bool isMilk() = 0;
	virtual bool isMeat() = 0;
};

#endif
