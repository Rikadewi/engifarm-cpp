//File : coop.h
#ifndef coop_H
#define coop_H

#include "land.h"

//coop merupakan turunan dari kelas land
class Coop : public Land{
public:
    int render();  //mengembalikan char yang akan diprint
};

#endif
