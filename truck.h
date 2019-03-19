//File: truck.h

#ifndef truck_H
#define truck_H

#include "facility.h"

//Truck merupakan turunan dari class Facility

class Truck : public Facility{
public:
    char render(); //mengembalikan char yang akan diprint pada map
    bool isAvailable(); //mengembalikan true jika truck bisa dipakai
private:
    int tick; //melambangkan seberapa lama lagi hingga truck bisa dipakai
};
#endif
