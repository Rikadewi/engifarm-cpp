#include "../mixer.h"
#include "../Product/beefomellete.h"
#include "../Product/platycowpancake.h"
#include "../Product/plachicksoup.h"

SideProduct Mixer::mix(ChickenEgg* egg, CowMeat* meat){
    BeefOmellete beef;
    delete egg;
    delete meat;
    return beef;
}

SideProduct Mixer::mix(PlatypusEgg* egg, CowMilk* milk){
    PlatycowPancake pancake;
    delete egg;
    delete milk;
    return pancake;
}

SideProduct Mixer::mix(ChickenMeat* meat, PlatypusMilk* milk){
    PlachickSoup soup;
    delete meat;
    delete milk;
    return soup;
}

int Mixer::render(){

}