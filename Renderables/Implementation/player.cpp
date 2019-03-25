//File: player.cpp
#include "../player.h"

Player::Player() : water(DEFWATER), money(DEFMONEY){

}

void Player::move(){
    List<char> around = lookAround();
    int idx = around.find(charLand);
    if(idx == -1){
        idx = around.find(charLandBerumput);
    }
    if(idx == -1){
        throw "Tidak ada space";
    }else{
        setY(idx%COL);
        setX(idx/COL);
    }
}

void Player::talk(){

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