//File: player.cpp
#include "../player.h"


Player::Player() : water(DEFWATER), money(DEFMONEY){

}

// void Player::cekPosisi (int i, int& x, int& y){
//   if(i == 0){
//     y = getY()-1;
//     x = getX();
//   }
//   if(i == 1){
//     x = getX()+1;
//     y = getY();
//   }
//   if(i == 2){
//     y = getY()+1;
//     x = getX();
//   }
//   if(i == 3){
//     x = getX()-1;
//     y = getY();
//   }
// }
// void Player::move(){
//     List<int> around = lookAround();
//     bool found = false;
//     int i = 0;
//     while ((!found) && (i<4)){
//         if(isLand(around.get(i))){
//             found = true;
//         }else{
//             i++;
//         }
//     }
//     if(!found){
//         throw "Tidak ada Space";
//     }else{
//         //problem dlm 1 petak ada land ada living things
//         int x, y;
//         cekPosisi(i, x, y);
//         setX(x);
//         setY(y);
//     }
// }
//
// void Player::talk(FarmAnimal& F){
//     // List<int> around = lookAround();
//     // bool found = false;
//     // int i = 0;
//     // while ((!found) && (i<4)){
//     //     if(isAnimal(around.get(i))){
//     //         found = true;
//     //     }else{
//     //         i++;
//     //     }
//     // }
//     // if(!found){
//     //     throw "Tidak ada Hewan";
//     // }else{
//     //     //problem dlm 1 petak ada land ada living things
//     //     int x, y;
//     //     cekPosisi(i, x, y);
//     //     //matriks [x][y].bersuara()
//     // }
//     F.bersuara();
// }
//
// void Player::interact(Renderables& R){
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
//     int id = R.render();
//     if(R.isFacility(id)){
//         if(id == 19){
//             if(water < MAXWATER){
//                 water++;
//             }else{
//                 throw "Air penuh";
//             }
//         }
//         if(id == 20){
//             //
//         }
//
//     }
// }
//
// void Player::kill(FarmAnimal& F){
//     // List<int> around = lookAround();
//     // bool found = false;
//     // int i = 0;
//     // while ((!found) && (i<4)){
//     //     if(isAnimal(around.get(i))){
//     //         int x, y;
//     //         cekPosisi(i, x, y);
//     //         //matriks [x][y].isMeat()
//     //         if(true){
//     //             found = true;
//     //             //animal.kill()?
//     //         }else{
//     //             i++;
//     //         }
//     //     }else{
//     //         i++;
//     //     }
//     // }
//     // if(!found){
//     //     throw "Tidak ada hewan untuk dibunuh";
//     // }else{
//     //     //kalo ada things.kill() nda perlu
//     // }
//     if (F.isMeat()){
//         if(inventory.getSize() < MAXBAG){
//             inventory.add(F.getProduct());
//         }else{
//             throw "Inventory penuh";
//         }
//         // F.getProduct();
//
//     }else{
//         throw "Bukan meat producing animal";
//     }
// }
//
// void Player::grow(){
//     //matriks[getX()][getY()].setRumput();
//     if(water > 0){
//         water--;
//     }else{
//         throw "Air tidak cukup";
//     }
// }
//
int Player::render(){
    return 22;
}
