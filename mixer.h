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

//mixer merupakan turunan dari facility
class Mixer : public Facility{
public:
    char render(); //mengembalikan char yang akan diprint pada map
    SideProduct mix(ChickenEgg, CowMeat); //menghasilkan beefomellete, mengurangi jumlah ChickenEgg dan CowMeat masing-masing satu.
    SideProduct mix(PlatypusEgg, CowMilk); //menghasilkan platycow pancake, mengurangi jumlah PlatypusEgg dan CowMilk masing-masing satu
    SideProduct mix(ChickenMeat, PlatypusMilk); //menghasilkan plachick soup, mengurangi jumlah PlatypusMilk dan ChickenEgg masing-masing satu.
};

#endif
