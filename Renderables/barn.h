//File : barn.h
#ifndef barn_H
#define barn_H

#include "land.h"

//barn merupakan turunan dari land
class Barn : public Land{
public:
    int render();  //mengembalikan char yang akan diprint
};

#endif
