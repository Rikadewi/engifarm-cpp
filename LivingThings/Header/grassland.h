//File : grassland.h
#ifndef grassland_H
#define grassland_H

#include "land.h"

class GrassLand : public Land{
public:
    GrassLand();
    int render();  //mengembalikan char yang akan diprint
};
#endif