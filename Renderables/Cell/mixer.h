//File : mixer.h
#ifndef mixer_H
#define mixer_H

#include "facility.h"
#include "../../Product/Sideproduct/sideproduct.h"
#include "../../Product/Farmproduct/chickenegg.h"
#include "../../Product/Farmproduct/platypusegg.h"
#include "../../Product/Farmproduct/chickenmeat.h"
#include "../../Product/Farmproduct/cowmeat.h"
#include "../../Product/Farmproduct/cowmilk.h"
#include "../../Product/Farmproduct/platypusmilk.h"

class Mixer : public Facility{
public:
    char render();
    SideProduct mix(ChickenEgg, CowMeat);
    SideProduct mix(PlatypusEgg, CowMilk);
    SideProduct mix(ChickenMeat, PlatypusMilk);
};

#endif
