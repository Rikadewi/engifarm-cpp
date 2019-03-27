//File: player.cpp
#include "../player.h"

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

Player::Player() : water(DEFWATER), money(DEFMONEY){

}

void Player::move(){
    List<int> around = lookAround();
    bool found = false;
    int i = 0;
    while ((!found) && (i<4)){
        if(isLand(around.get(i))){
            found = true;
        }else{
            i++;
        }
    }
    if(!found){
        throw "Tidak ada Space";
    }else{
        //problem dlm 1 petak ada land ada living things
        int x, y;
        cekPosisi(i, x, y);
        setX(x);
        setY(y);
    }
}

void Player::talk(){
    List<int> around = lookAround();
    bool found = false;
    int i = 0;
    while ((!found) && (i<4)){
        if(isAnimal(around.get(i))){
            found = true;
        }else{
            i++;
        }
    }
    if(!found){
        throw "Tidak ada Hewan";
    }else{
        //problem dlm 1 petak ada land ada living things
        int x, y;
        cekPosisi(i, x, y);
        //matriks [x][y].bersuara()
    }
}

void Player::interact(){
    List<int> around = lookAround();
    bool found = false;
    int i = 0;
    while ((!found) && (i<4)){
        if(isFacility(around.get(i))){
            //facility.interact()?
            found = true;
        }else{
            if(isAnimal(around.get(i))){
                int x, y;
                cekPosisi(i, x, y);
                //matriks [x][y].isEgg() or matriks [x][y].isMilk()
                if(true){
                    found = true;
                    //animal.interact()?
                }else{
                    i++;
                }
            }else{
                i++;
            }
        }
    }
    if(!found){
        throw "Tidak bisa interact";
    }else{
        //kalo ada things.interact() nda perlu
    }
}

void Player::kill(){
    List<int> around = lookAround();
    bool found = false;
    int i = 0;
    while ((!found) && (i<4)){
        if(isAnimal(around.get(i))){
            int x, y;
            cekPosisi(i, x, y);
            //matriks [x][y].isMeat()
            if(true){
                found = true;
                //animal.kill()?
            }else{
                i++;
            }
        }else{
            i++;
        }
    }
    if(!found){
        throw "Tidak ada hewan untuk dibunuh";
    }else{
        //kalo ada things.kill() nda perlu
    }
}

void Player::grow(){
    //matriks[getX()][getY()].setRumput();
    water--;
}

char Player::render(){
    return 'P';
}