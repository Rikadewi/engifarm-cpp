#include<iostream>
#include "gameengine.h"
using namespace std;

Cell*** GameEngine::getWorld() {
    return world;
}


int GameEngine::getXPlayer(){
    return XPlayer;
}

int GameEngine::getYPlayer() {
    return YPlayer;
}

Player* GameEngine::getEngi(){
    return world[XPlayer][YPlayer]->getPlayer();
}

GameEngine::GameEngine(){
    tick = 0;
    world = new Cell**[WORLDSIZE];
    //Inisialisasi dunia dan set semua petak menjadi graassland
    for(int i=0;i<WORLDSIZE;i++){
        world[i]=new Cell*[WORLDSIZE];
    }
    for(int i=0;i<WORLDSIZE;i++){
        for(int j=0; j<WORLDSIZE; j++){ 
            // if ( j != 12 || ((i!=0)&&(i!=1)&&(i!=2)))
            {
                world[i][j] = new Land(true,NULL,grassLand);
            } 
        }
    }

    //Membuat Coop
    // for(int i=0;i<4;i++){
    //     for(int j=1; j<4;j++){
    //         //Butuh bikin Coop!
    //         // coop* c;
    //         // world[i][j] = c;
    //     }
    // }

    // //Membuat Barn
    // for(int i=0;i<7;i++){
    //     for(int j=5; j<10;j++){
    //         //Butuh bikin barn!
    //         // barn *b;
    //         // world[i][j] = b;
    //     }
    // }
    
    //Menetapkan Facility MASIH SALAH NARONYA, MIXER WELL TRUCK BUTUH CONSTRUCTOR
    // Mixer m;
    // Well w;
    // Truck t;
    // world[0][12] = &m;
    // world[1][12] = &w;
    // world[2][12]= &t;
}

int GameEngine::look(int i, int j){
    if(i>=0 && i<20 && j>=0 && j<20){
        if((getID(i,j)>=1 && getID(i,j)<=12) || (getID(i,j)>=19 && getID(i,j)<=22)){
                return world[i][j]->render();
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

List<int> GameEngine::lookAround(int x, int y){
    List<int> around;
    //lihat objek utara (x-1)(y)
    around.add(look(x-1,y));
    //lihat objek timur (x)(y+1)
    around.add(look(x,y+1));
    //lihat objek selatan (x+1)(y)
    around.add(look(x+1,y));
    //lihat objek barat (x)(y-1)
    around.add(look(x,y-1));
    return around;
}

void GameEngine::handleInteract(){
    //Mendapatkan list yang berisi objek disekitarnya
    List<int> around = lookAround(XPlayer,YPlayer);
    bool foundAnimal= false;
    bool foundFacility = false;
    int i=0;
    while ((!foundAnimal || !foundFacility) && (i<4)){
        //jika animal
        if(around.getElmt(i)>=1 && around.getElmt(i)<=10){
            foundAnimal = true;
        }else if (around.getElmt(i)>=19 && around.getElmt(i)<=21){ //facility
            foundFacility=true;
        }else{
            i++;
        }
    }

    if (foundAnimal){
        FarmAnimal* temp = world[XPlayer-1][YPlayer]->getAnimal();
        getEngi()->interact(*temp);
    }

    if(foundFacility){
        int id = around.getElmt(i);
        if(around.getElmt(i)==19){//well
            getEngi()->interactWell();
        }else if (around.getElmt(i)==20){//mixer
            getEngi()->interactMixer();
        }else if (around.getElmt(i)==21){//truck
            getEngi()->interactTruck();
        }        
    }
    

}

void GameEngine::handleMoveAnimal(int x, int y){
    List <int> around = lookAround(x,y);
    FarmAnimal* f = world[x][y]->getAnimal();
    bool found = false;
    int i = 0;
    while ((!found)&&(i<4)){
        //penghasil telur move bisa ke coop 15 16
        if(f->isEgg()){ 
            if(around.getElmt(i)==15 || around.getElmt(i)==16){
                found = true;
            }
        }
         //penghasil daging move bisa ke barn 13 14
        if(f->isMeat()){
            if(around.getElmt(i)==13 || around.getElmt(i)==14){
                found = true;
            }
        }
        //move bisa ke grassland 17 18
        if(f->isMilk()){
            if(around.getElmt(i)==17 || around.getElmt(i)==18){
                found = true;
            }
        }

        if(!found && i<4){
            i++;
        }
    }
    if(found){
        if (i==0){//utara (x-1)(y)
            world[x][y]->setAnimal(NULL);
            world[x-1][y]->setAnimal(f);
        }else if (i==1){ //timur (x)(y+1)
            world[x][y]->setAnimal(NULL);
            world[x][y+1]->setAnimal(f);
        }else if (i==2){//selatan (x+1)(y)
            world[x][y]->setAnimal(NULL);
            world[x+1][y]->setAnimal(f);
        }else if (i==3){//barat (x)(y-1)
            world[x][y]->setAnimal(NULL);
            world[x][y-1]->setAnimal(f);
        }
    }else{
        throw "Tidak ada space";
    }
}

//BELOM IMPLEMENTASI
void GameEngine::handleMove(int n){
    List<int> around = lookAround(XPlayer, YPlayer);
    bool found = false;
    int i = 0;

    if (n==1){//atas
        if((around.getElmt(0))>=13 && (around.getElmt(0))<=18){
            XPlayer--;
        }
        else{
            throw "Tidak dapat melakukan move";
        }
    } else if (n==2){//kanan
        if((around.getElmt(1))>=13 && (around.getElmt(1))<=18){
            YPlayer++;
        }
        else{
            throw "Tidak dapat melakukan move";
        }
    } else if (n==3){//kanan
        if((around.getElmt(2))>=13 && (around.getElmt(2))<=18){
            XPlayer++;
        }
        else{
            throw "Tidak dapat melakukan move";
        }
    } else if (n==4){//kanan
        if((around.getElmt(3))>=13 && (around.getElmt(3))<=18){
            YPlayer--;
        }
        else{
            throw "Tidak dapat melakukan move";
        }
    }
}

void GameEngine::handleGrow(){
    world[getXPlayer()][getYPlayer()]->updateCell(grow);
}

void GameEngine::handleTalk(){
    List<int> around = lookAround(XPlayer, YPlayer);
    if(around.getElmt(0)>=1 && around.getElmt(0)<=12){
        FarmAnimal* temp = world[XPlayer-1][YPlayer]->getAnimal();
        getEngi()->talk(*temp);
    }else if(around.getElmt(1)>=1 && around.getElmt(1)<=12){
        FarmAnimal* temp = world[XPlayer][YPlayer+1]->getAnimal();
        getEngi()->talk(*temp);
    }else if(around.getElmt(2)>=1 && around.getElmt(2)<=12){
        FarmAnimal* temp = world[XPlayer+1][YPlayer]->getAnimal();
        getEngi()->talk(*temp);
    }else if(around.getElmt(3)>=1 && around.getElmt(3)<=12){
        FarmAnimal* temp = world[XPlayer][YPlayer+1]->getAnimal();
        getEngi()->talk(*temp);
    }
}

void GameEngine::handleKill(){
    List<int> around = lookAround(XPlayer, YPlayer);
    bool hasKill = false;
    int i = 0;
    while (!hasKill && i<4){
        //penghasil daging id = 1 2 3 4 5 6 11 12
        if((around.getElmt(i)>=1 && around.getElmt(i)<=6) || around.getElmt(i)==11 || around.getElmt(i)==12){
            hasKill=true;
        }else{
            i++;
        }
    }
    if (i==0){//kill animal utara
        FarmAnimal *temp = world[XPlayer-1][YPlayer]->getAnimal();
        getEngi()->kill(*temp);
        world[XPlayer-1][YPlayer]->updateCell(removeAnimal);
    }else if (i==1){ //kill animal timur
        FarmAnimal *temp = world[XPlayer][YPlayer+1]->getAnimal();
        getEngi()->kill(*temp);
        world[XPlayer][YPlayer+1]->updateCell(removeAnimal);
    }else if (i==2){ //kill animal selatan
        FarmAnimal *temp = world[XPlayer+1][YPlayer]->getAnimal();
        getEngi()->kill(*temp);
        world[XPlayer+1][YPlayer]->updateCell(removeAnimal);
    }else if (i==3){ //kill animal barat
        FarmAnimal *temp = world[XPlayer][YPlayer-1]->getAnimal();
        getEngi()->kill(*temp);
        world[XPlayer][YPlayer-1]->updateCell(removeAnimal);
    }

}

int GameEngine::getID(int i,int j){
    return world[i][j]->render(); 
}

/* FUNGSI UPDATE */
void GameEngine::updateGame(){
    tick++;
    //Menggerakan animal
    for(int i = 0; i<WORLDSIZE; i++){
        for(int j =0 ; j<WORLDSIZE; j++){
            if(getID(i,j) < 13) { //Jika merupakan animal
                //Gerakan Animal Tsb   
                handleMoveAnimal(i,j);
                //Bikin Animal tsb makan
                world[i][j]->updateCell(makan);
                //kurangin living time, sekaligus bunuh yang mati
                world[i][j]->updateCell(checkAnimal);
            }
            else if (getID(i,j) == 21 ){ //Jika merupakan truck
                //Ubah keadaan trucknya
                world[i][j]->updateCell(readyTruck);
            }
            //Kasus lain???
        }
    }       
}
void GameEngine::renderer(int n){
    switch (n)
    {   
        case 0 : //Out of Bounds

            break;
        case 1 : //Chicken Kampung

            break;
        case 2 : 

            break;
        case 3 : //Chicken Jago

            break;
        case 4 : 

            break;
        case 5 : //Cow

            break;
        case 6 :

            break;
        case 7 : // Golden Platypus

            break;
        case 8 : 

            break;
        case 9 : // Platypus

            break;
        case 10 :

            break;
        case 11 : //Bull

            break;
        case 12 :

            break;
        case 13 : //Barn

            break;
        case 14 :

            break;
        case 15 : //Coop

            break;
        case 16 :

            break;
        case 17: //GrassLand Ga Berumput
            break;
        case 18: //GrassLand Berumput
            cout << "\033[42m" << 'G' << " \033[0m"; //Print Kotak background Hijau
            break;
        default:
            break;
        case 19 : //Well

            break;
        case 20 : //Mixer

            break;
        case 21 : //Truck

            break;
        case 22 : //player

            break;
    }
}
//Fungsi untuk print Map
void GameEngine::printMap(){
    for (int i = 0; i<WORLDSIZE; i++){
        for(int j=0; j<WORLDSIZE; j++){
            renderer(world[i][j]->render());
        }
        cout << endl;
    }
}
void GameEngine::printMessage(string msg) {
    cout<< msg << endl;
}