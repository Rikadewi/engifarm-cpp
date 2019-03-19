//File : land.h
#ifndef land_H
#define land_H

#include "cell.h"

class Land : public Cell {
protected:
  bool isRumput; 
public:
  char render();  //mengembalikan char yang akan diprint
  Land(); //set isRumput = false
  void setRumput(); //set isRumput menjadi true jika merupakan grassland, false ketika dimakan animal
};

#endif
