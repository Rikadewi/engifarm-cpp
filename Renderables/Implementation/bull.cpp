//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
Bull::Bull(){
	FarmAnimal::egg = false;
	FarmAnimal::milk = false;
	FarmAnimal::meat = true;
}
//prosedur Bersuara menuliskan suara Bull ke layar
void Bull::bersuara(){
	cout << "(Manly) Moooo..." << endl;
}

char Bull::render(){
	return 'B';
}