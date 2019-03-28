#include "Renderables/barn.h"
#include "Renderables/bull.h"
#include "Renderables/cell.h"
#include "Renderables/chickenjago.h"
#include "Renderables/chickenkampung.h"
#include "Renderables/coop.h"
#include "Renderables/cow.h"
#include "Renderables/facility.h"
#include "Renderables/farmanimal.h"
#include "Renderables/goldenplatypus.h"
#include "Renderables/grassland.h"
#include "Renderables/land.h"
#include "Renderables/livingthings.h"
#include "Renderables/mixer.h"
#include "Renderables/platypus.h"
#include "Renderables/player.h"
#include "Renderables/renderables.h"
#include "Renderables/truck.h"
#include "Renderables/well.h"
#include "Product/beefomellete.h"
#include "Product/chickenegg.h"
#include "Product/chickenmeat.h"
#include "Product/cowmeat.h"
#include "Product/cowmilk.h"
#include "Product/farmproduct.h"
#include "Product/plachicksoup.h"
#include "Product/platycowpancake.h"
#include "Product/platypusegg.h"
#include "Product/platypusmilk.h"
#include "Product/product.h"
#include "Product/sideproduct.h"
#include "list.h"

#define MAX_ROW 10
#define MAX_COL 10

using namespace std;
int main(){

  // LivingThings** peta1[MAX_ROW][MAX_COL];
  Player p1;
  // p1.setX(0);
  // p1.setY(0);

  // peta1[0][0] = p1;
  LivingThings* peta1 [MAX_ROW];
  peta1[0] = &p1;

  // peta1 = new LivingThings*[MAX_ROW];
  // for(int i=0;i<MAX_ROW;i++){
  //   peta1[i] = new LivingThings[MAX_COL];
  // }

  // for(int i=0;i<MAX_ROW;i++){
  //   for(int j =0; j<MAX_COL;j++){
  //     peta1[i][j]= i*j;
  //   }
  // }

  // for(int i=0;i<MAX_ROW;i++){
  //   for(int j =0; j<MAX_COL;j++){
  //     cout<< peta1[i][j] << " ";
  //   }
  //   cout<<endl;
  // }

  return 0;
}
