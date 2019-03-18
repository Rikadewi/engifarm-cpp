//File : mixer.h
#ifndef mixer_H
#define mixer_H

#include "facility.h"
#include "chickenegg.h"
#include "platypusegg.h"
#include "chickenmeat.h"
#include "cowmeat.h"
#include "cowmilk.h"
#include "platypusmilk.h"

class Mixer : public Facility{
public:
    void render();
    void mix(ChickenEgg);
    void mix(PlatypusEgg);
    void mix(ChickenMeat);
    void mix(CowMeat);
    void mix(CowMilk);
    void mix(PlatypusMilk);
};

#endif
