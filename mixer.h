//File : mixer.h
#ifndef mixer_H
#define mixer_H

#include "facility.h"
#include "sideproduct.h"
#include "chickenegg.h"
#include "platypusegg.h"
#include "chickenmeat.h"
#include "cowmeat.h"
#include "cowmilk.h"
#include "platypusmilk.h"

class Mixer : public Facility{
public:
    char render();
    SideProduct mix(ChickenEgg, CowMeat);
    SideProduct mix(PlatypusEgg, CowMilk);
    SideProduct mix(ChickenMeat, PlatypusMilk);
};

#endif
