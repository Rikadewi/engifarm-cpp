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
    SideProduct mix(ChickenEgg);
    SideProduct mix(PlatypusEgg);
    SideProduct mix(ChickenMeat);
    SideProduct mix(CowMeat);
    SideProduct mix(CowMilk);
    SideProduct mix(PlatypusMilk);
};

#endif
