//File: player.cpp
#include "../player.h"

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
        if(i == 0){
            setY(getY()-1);
        }
        if(i == 1){
            setX(getX()+1);
        }
        if(i == 2){
            setY(getY()+1);
        }
        if(i == 3){
            setX(getX()-1);
        }
        
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
        int x;
        int y;
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
        //matriks [x][y].talk()
        
    }
}

void Player::interact(){
    
}

void Player::kill(){

}

void Player::grow(){

}

char Player::render(){
    return 'P';
}