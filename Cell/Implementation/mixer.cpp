#include "../Header/mixer.h"
#include "../../Product/Header/beefomellete.h"
#include "../../Product/Header/platycowpancake.h"
#include "../../Product/Header/plachicksoup.h"

SideProduct Mixer::mix(ChickenEgg egg, CowMeat meat){
    BeefOmellete beef;
    // delete egg;
    // delete meat;
    return beef;
}

SideProduct Mixer::mix(PlatypusEgg egg, CowMilk milk){
    PlatycowPancake pancake;
    // delete egg;
    // delete milk;
    return pancake;
}

SideProduct Mixer::mix(ChickenMeat meat, PlatypusMilk milk){
    PlachickSoup soup;
    // delete meat;
    // delete milk;
    return soup;
}

int Mixer::render(){
    return 20;
}