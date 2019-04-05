//File: player.cpp
#include "../Header/player.h"
#include <string>
#include <sstream>
Player::Player() : water(DEFWATER), money(DEFMONEY){
    
}

string Player::talk(FarmAnimal *F ){
     return F->bersuara();
}

void Player::interactWell(){
    if(water < MAXWATER){
        water++;
    }else{
        throw "Ember penuh";
    }
}

void Player::interactMixer(){
    bool hasMix = false;

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
    if(F.isMeat()&& (!F.isEgg() ||! F.isMilk())){
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

void Player::kill(FarmAnimal *F){
    if(inventory.getNeff() < MAXBAG){
        inventory.add(F->getProduct(true));
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

int Player::getWater(){
    return water;
}

long Player::getMoney(){
    return money;
}

List <Product>  Player::getInventory(){
    return inventory;
}
