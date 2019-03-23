//File: player.cpp
#include "../player.h"

Player::Player() : water(DEFWATER), money(DEFMONEY){

}

void Player::talk(){
    List<char> around = lookAround();
    if (around.find(charLand) != -1){

    }
}