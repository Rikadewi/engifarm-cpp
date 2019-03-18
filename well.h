//File : well.h
#ifndef well_H
#define well_H

#include "facility.h"

class Well : public Facility{
public:
    char render();
    void fillWater();
};

#endif
