//File: player.cpp
#include "../Header/player.h"
#include <string>
Player::Player() : water(DEFWATER), money(DEFMONEY){

}

// void Player::cekPosisi (int i, int& x, int& y){
//     if(i == 0){
//         y = getY()-1;
//         x = getX();
//     }
//     if(i == 1){
//         x = getX()+1;
//         y = getY();
//     }
//     if(i == 2){
//         y = getY()+1;
//         x = getX();
//     }
//     if(i == 3){
//         x = getX()-1;
//         y = getY();
//     }
// }



void Player::talk(FarmAnimal& F){
    // List<int> around = lookAround();
    // bool found = false;
    // int i = 0;
    // while ((!found) && (i<4)){
    //     if(isAnimal(around.get(i))){
    //         found = true;
    //     }else{
    //         i++;
    //     }
    // }
    // if(!found){
    //     throw "Tidak ada Hewan";
    // }else{
    //     //problem dlm 1 petak ada land ada living things
    //     int x, y;
    //     cekPosisi(i, x, y);
    //     //matriks [x][y].bersuara()
    // }
    F.bersuara();
}

// void Player::interact(Facility& F){
//     // List<int> around = lookAround();
//     // bool found = false;
//     // int i = 0;
//     // while ((!found) && (i<4)){
//     //     if(isFacility(around.get(i))){
//     //         //facility.interact()?
//     //         found = true;
//     //     }else{
//     //         if(isAnimal(around.get(i))){
//     //             int x, y;
//     //             cekPosisi(i, x, y);
//     //             //matriks [x][y].isEgg() or matriks [x][y].isMilk()
//     //             if(true){
//     //                 found = true;
//     //                 //animal.interact()?
//     //             }else{
//     //                 i++;
//     //             }
//     //         }else{
//     //             i++;
//     //         }
//     //     }
//     // }
//     // if(!found){
//     //     throw "Tidak bisa interact";
//     // }else{
//     //     //kalo ada things.interact() nda perlu
//     // }
//     int id = F.render();
//     if(id == 19){
//         //interaksi dengan well
//         if(water < MAXWATER){
//             water++;
//         }
//     }else{
//         if(id == 20){
//             //interaksi dengan mixer

//         }else{
//             //interaksi dengan truck
//             throw "Bukan mixer dan well";
//             //interact (F);
//         }
//     }
    
//         // if(id == 21){
//         //     //interaksi dengan truck
//         //     if(R.isAvailable()){
//         //         while(!inventory.isEmpty()){

//         //         }
//         //     }else{
//         //         throw "Truck tidak ada";
//         //     }interactWell
//         // }
        
// }

void Player::interactWell(){
    if(water < MAXWATER){
        water++;
    }
}

void Player::interactMixer(){
    bool hasMix = false;
    if (!hasMix){
        //mixer jenis 1 (chcken egg, cow meat) = beef omellete
        bool found1 = false;
        bool found2 = false;
        int idx1 = 0;
        int idx2 = 0;
        //cari chicken egg = 1
        while (idx1<=inventory.getLastIdx() && !found1){
            Product temp = inventory.getElmt(idx1);
            if (temp.getID()==1){
                found1 = true;
            }else{
                idx1++;
            }
        }
        //cari cowmeat = 3
        while (idx2<=inventory.getLastIdx() && !found2){
            Product temp = inventory.getElmt(idx2);
            if (temp.getID()==1){
                found2 = true;
            }else{
                idx2++;
            }
        }

        if(found1 && found2){
            hasMix = true;
            Product* temp;
            inventory.removeAt(idx1, temp);
            inventory.removeAt(idx2, temp);
            SideProduct beefomellete = BeefOmellete();
            inventory.add(beefomellete);
        }
    }

    if(!hasMix){
        //mixer jenis 2 (platypus] egg, cow milk) = platypus pancake
        bool found1 = false;
        bool found2 = false;
        int idx1 = 0;
        int idx2 = 0;
        //cari platypus egg = 5
        while (idx1<=inventory.getLastIdx() && !found1){
            Product temp = inventory.getElmt(idx1);
            if (temp.getID()==5){
                found1 = true;
            }else{
                idx1++;
            }
        }
        //cari cowmilk = 4
        while (idx2<=inventory.getLastIdx() && !found2){
            Product temp = inventory.getElmt(idx2);
            if (temp.getID()==4){
                found2 = true;
            }else{
                idx2++;
            }
        }

        if(found1 && found2){
            hasMix = true;
            Product* temp;
            inventory.removeAt(idx1, temp);
            inventory.removeAt(idx2, temp);
            SideProduct platycowpancake = PlatycowPancake();
            inventory.add(platycowpancake);
        }
    }

    if(!hasMix){
        //mixer jenis 3 (platypus milk, chicken meat) = plachick soup
        bool found1 = false;
        bool found2 = false;
        int idx1 = 0;
        int idx2 = 0;
        //cari platypus milk = 6
        while (idx1<=inventory.getLastIdx() && !found1){
            Product temp = inventory.getElmt(idx1);
            if (temp.getID()==6){
                found1 = true;
            }else{
                idx1++;
            }
        }
        //cari chickenmeat = 2
        while (idx2<=inventory.getLastIdx() && !found2){
            Product temp = inventory.getElmt(idx2);
            if (temp.getID()==2){
                found2 = true;
            }else{
                idx2++;
            }
        }

        if(found1 && found2){
            hasMix = true;
            Product* temp;
            inventory.removeAt(idx1, temp);
            inventory.removeAt(idx2, temp);
            SideProduct plachicksoup = PlachickSoup();
            inventory.add(plachicksoup);
        }
    }
}

void Player::interactTruck(){
    while(!inventory.isEmpty()){
        Product* temp;
        inventory.removeAt(inventory.getLastIdx(), temp);
        if(temp->getHarga() + money > MAXMONEY){
            money = MAXMONEY;
        }else{
            money +=temp->getHarga();
        }
        delete temp;
    }
}


void Player::interact(FarmAnimal& F){
    if(F.isMeat()){
        throw "Tidak bisa berinteraksi dengan meat producing animal";
    }else{
        if(inventory.getSize() < MAXBAG){
            try{
                inventory.add(F.getProduct(false));
            }catch (string s){
                throw s;
            }
        }else{
            throw "Inventory penuh";
        }
    }
}

void Player::kill(FarmAnimal& F){
    if(inventory.getSize() < MAXBAG){
            inventory.add(F.getProduct(true));
    }else{
        throw "Inventory penuh";
    }
}

void Player::grow(){
    if(water > 0){
        water--;    
    }else{
        throw "Air tidak cukup";
    }
}

int Player::render(){
    return 22;
}