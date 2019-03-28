#include "../Header/facility.h"
#include "../../Product/product.h"
#include "../../Product/sideproduct.h"
#include "../../Product/chickenegg.h"
#include "../../Product/platypusegg.h"
#include "../../Product/chickenmeat.h"
#include "../../Product/cowmeat.h"
#include "../../Product/cowmilk.h"
#include "../../Product/platypusmilk.h"
#include "../Header/mixer.h"
#include "../../Product/beefomellete.h"
#include "../../Product/platycowpancake.h"
#include "../../Product/plachicksoup.h"
#include <iostream>
using namespace std;

int main(){
    Mixer m;
    CowMeat cowmeat;
    ChickenEgg chickegg;
    PlatypusEgg platyegg;
    PlatypusMilk platymilk;
    CowMilk cowmilk;
    ChickenMeat chickmeat;
    SideProduct s;
    s = m.mix(chickegg, cowmeat);
    int price = s.getHarga();
    cout << price << endl;
    s = m.mix(chickmeat, platymilk);
    price = s.getHarga();
    cout << price << endl;
    s = m.mix(platyegg, cowmilk);
    price = s.getHarga();
    cout << price << endl;
}