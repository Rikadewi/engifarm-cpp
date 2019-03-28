//File : mixer.h
#ifndef mixer_H
#define mixer_H

#include "facility.h"
#include "../../Product/Header/beefomellete.h"
#include "../../Product/Header/chickenegg.h"
#include "../../Product/Header/platypusegg.h"
#include "../../Product/Header/chickenmeat.h"
#include "../../Product/Header/cowmeat.h"
#include "../../Product/Header/cowmilk.h"
#include "../../Product/Header/platypusmilk.h"

//mixer merupakan turunan dari facility
class Mixer : public Facility{
public:
    int render(); //mengembalikan char yang akan diprint pada map
    SideProduct mix(ChickenEgg , CowMeat); //menghasilkan beefomellete, mengurangi jumlah ChickenEgg dan CowMeat masing-masing satu.
    SideProduct mix(PlatypusEgg , CowMilk); //menghasilkan platycow pancake, mengurangi jumlah PlatypusEgg dan CowMilk masing-masing satu
    SideProduct mix(ChickenMeat , PlatypusMilk); //menghasilkan plachick soup, mengurangi jumlah PlatypusMilk dan ChickenEgg masing-masing satu.
};

#endif
