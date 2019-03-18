// File: farmanimal.h
#ifndef FARMANIMAL_H
#define FARMANIMAL_H

#include "livingthings.h"

class FarmAnimal : public LivingThings {
protected:
	bool hungry; //variabel penanda bahwa hewan lapar
	bool egg; //menandakan jenis hewan penghasil telur
	bool milk; //menandakan jenis hewan penghasil susu
	bool meat; //menandakan jenis hewan penghasil daging
	int living_time; //variabel penanda tick yang dimiliki sebelum hewan mati kelaparan
	bool hasProduct; // Animal sudah siap untuk product atau belum
public:
	//prosedur makan mengembalikan living_time menjadi default
	void makan();
	//prosedur update dipanggil setiap tick
	void update();
	//prosedur virtual void makeHungry
	void makeHungry();
	//fungsi boolean isHungry mengembalikan true jika atribut hungry bernilai true
	bool isHungry();
	//deklarasi fungsi pure virtual
	virtual void Bersuara() = 0;
	bool isEgg();
	bool isMilk();
	bool isMeat();
};

#endif
