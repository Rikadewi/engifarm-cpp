//File: player.cpp
#include "../Header/player.h"
#include <string>
Player::Player() : water(DEFWATER), money(DEFMONEY){

}

void Player::cekPosisi (int i, int& x, int& y){
    if(i == 0){
        y = getY()-1;
        x = getX();
    }
    if(i == 1){
        x = getX()+1;
        y = getY();
    }
    if(i == 2){
        y = getY()+1;
        x = getX();
    }
    if(i == 3){
        x = getX()-1;
        y = getY();
    }
}



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

void Player::interact(Facility& F){
    // List<int> around = lookAround();
    // bool found = false;
    // int i = 0;
    // while ((!found) && (i<4)){
    //     if(isFacility(around.get(i))){
    //         //facility.interact()?
    //         found = true;
    //     }else{
    //         if(isAnimal(around.get(i))){
    //             int x, y;
    //             cekPosisi(i, x, y);
    //             //matriks [x][y].isEgg() or matriks [x][y].isMilk()
    //             if(true){
    //                 found = true;
    //                 //animal.interact()?
    //             }else{
    //                 i++;
    //             }
    //         }else{
    //             i++;
    //         }
    //     }
    // }
    // if(!found){
    //     throw "Tidak bisa interact";
    // }else{
    //     //kalo ada things.interact() nda perlu
    // }
    int id = F.render();
    if(id == 19){
        //interaksi dengan well
        if(water < MAXWATER){
            water++;
        }
    }else{
        if(id == 20){
            //interaksi dengan mixer

        }else{
            //interaksi dengan truck
            throw "Bukan mixer dan well";
            //interact (F);
        }
    }
    
        // if(id == 21){
        //     //interaksi dengan truck
        //     if(R.isAvailable()){
        //         while(!inventory.isEmpty()){

        //         }
        //     }else{
        //         throw "Truck tidak ada";
        //     }
        // }
        
}


void Player::interact(Truck& T){
    if(T.isAvailable()){
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
    }else{
        throw "Truck tidak ada";
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
    // List<int> around = lookAround();
    // bool found = false;
    // int i = 0;
    // while ((!found) && (i<4)){
    //     if(isAnimal(around.get(i))){
    //         int x, y;
    //         cekPosisi(i, x, y);
    //         //matriks [x][y].isMeat()
    //         if(true){
    //             found = true;
    //             //animal.kill()?
    //         }else{
    //             i++;
    //         }
    //     }else{
    //         i++;
    //     }
    // }
    // if(!found){
    //     throw "Tidak ada hewan untuk dibunuh";
    // }else{
    //     //kalo ada things.kill() nda perlu
    // }
    if (F.isMeat()){
        if(inventory.getSize() < MAXBAG){
            inventory.add(F.getProduct(true));
        }else{
            throw "Inventory penuh";
        }
        // F.getProduct();
        
    }else{
        throw "Bukan meat producing animal";
    }
}

void Player::grow(){
    //matriks[getX()][getY()].setRumput();
    if(water > 0){
        water--;    
    }else{
        throw "Air tidak cukup";
    }
}

int Player::render(){
    return 22;
}