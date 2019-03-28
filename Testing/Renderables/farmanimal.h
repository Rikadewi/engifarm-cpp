// File: farmanimal.h
#ifndef FARMANIMAL_H
#define FARMANIMAL_H

#include "livingthings.h"
#include "../Product/farmproduct.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class FarmAnimal : public LivingThings {
protected://knpa nda private?
	bool hungry; //variabel penanda bahwa hewan lapar
	bool egg; //menandakan jenis hewan penghasil telur
	bool milk; //menandakan jenis hewan penghasil susu
	bool meat; //menandakan jenis hewan penghasil daging
	int living_time; //variabel penanda tick yang dimiliki sebelum hewan mati kelaparan
	bool hasProduct; // Animal sudah siap untuk product atau belum
	static int jumlah;
public:
	//konstruktor FarmAnimal, mengeset hungry dan hasProduct menjadi false, living_time mejadi default, menambah static int jumlah
	FarmAnimal();
	//destruktor FarmAnimal, mengurangi statis int jumlah
	~FarmAnimal();
	//prosedur makan mengembalikan living_time menjadi default
	void makan();
	// TIDAK PERLU prosedur update dipanggil setiap tick
	// void update();
	//prosedur virtual void makeHungry
	void makeHungry();
	//fungsi boolean isHungry mengembalikan true jika atribut hungry bernilai true
	bool isHungry();
	//deklarasi fungsi pure virtual
	virtual void bersuara() = 0;
	//prosedur move animal
	bool is_safe_to_move(int);
	// void Move() TIDAK PERLU;
	bool isEgg();
	bool isMilk();
	bool isMeat();
	virtual FarmProduct getProduct() = 0;
	static int getJumlah();
};

#endif
