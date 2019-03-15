#ifndef FARMANIMAL_H
#define FARMANIMAL_H


class FarmAnimal : public LivingThing {
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
	void makeHungry() = 0;
	//fungsi boolean isHungry mengembalikan true jika atribut hungry bernilai true
	bool isHungry();
	//deklarasi fungsi pure virtual
	virtual void Bersuara() = 0;
	virtual bool isEgg() = 0;
	virtual bool isMilk() = 0;
	virtual bool isMeat() = 0;
}

class ChickenJago : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
	ChickenJago();
	//prosedur Bersuara menuliskan suara ChickenJago ke layar
	void Bersuara();
	static const bool isEgg();
	static const bool isMilk();
	static const bool isMeat();
}

class ChickenKampung : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default 
	ChickenKampung();
	//prosedur Bersuara menuliskan suara ChickenKampung ke layar
	void Bersuara();
	static const bool isEgg();
	static const bool isMilk();
	static const bool isMeat();
}

class Cow : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default 
	Cow();
	//prosedur Bersuara menuliskan suara Cow ke layar
	void Bersuara();
	static const bool isEgg();
	static const bool isMilk();
	static const bool isMeat();
}

class Bull : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default 
	Bull();
	//prosedur Bersuara menuliskan suara Bull ke layar
	void Bersuara();
	static const bool isEgg();
	static const bool isMilk();
	static const bool isMeat();
}

class Platypus : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default 
	Platypus();
	//prosedur Bersuara menuliskan suara Platypus ke layar
	void Bersuara();
	static const bool isEgg();
	static const bool isMilk();
	static const bool isMeat();
}

class GoldenPlatypus : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default 
	GoldenPlatypus();
	//prosedur Bersuara menuliskan suara GoldenPlatypus ke layar
	void Bersuara();
	static const bool isEgg();
	static const bool isMilk();
	static const bool isMeat();
}

#endif
