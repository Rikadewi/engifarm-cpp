#include "gameengine.h"

GameEngine::GameEngine(){
    tick = 0;
    for(int i=0;i<WORLDSIZE;i++){
        world[i]=new Cell*[WORLDSIZE];
    }
    for(int i=0;i<WORLDSIZE;i++){
        for(int j=0; j<WORLDSIZE; j++){
            if ((i!=18)&&((j!=3)||(j!=9)||(j!=16))){
                // Land l;
                // world[i][j] = &l;
            }
        }
    }
    for(int i=1;i<10;i++){
        for(int j=1; j<10;j++){
            // world[i][j] -> setType(coop);
        }
        for(int j=9; j<18;j++){
            // world[i][j] -> setType(grassLand);
        }
    }
    for(int i=10;i<16;i++){
        // for(int j=1; j<){
            
        // }
    }
    int i=18;
    Mixer m;
    Well w;
    Truck t;
    world[i][3] = &m;
    world[i][8] = &w;
    world[i][16]= &t;
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
    List<int> around = lookAround(engi.getX(),engi.getY());
    bool foundAnimal= false;
    bool foundFacility = false;
    int i=0;
    while ((!foundAnimal || !foundFacility) && (i<4)){
        //jika animal
        if(around.getElmt(i)>=1 && around.getElmt(i)<=10){
            foundAnimal = true;
        }else{ 
            if (around.getElmt(i)>=19 && around.getElmt(i)<=21){ //facility
                foundFacility=true;
            }else{
                i++;
            }
        }
    }

    if (foundAnimal){
        FarmAnimal* temp = world[engi.getX()-1][engi.getY()]->getAnimal();
        engi.interact(*temp);
    }

    if(foundFacility){
        int id = around.getElmt(i);
        if(around.getElmt(i)==19){//well
            
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
            f->setX(x-1);
        }else if (i==1){ //timur (x)(y+1)
            f->setY(y+1);
        }else if (i==2){//selatan (x+1)(y)
            f->setX(x+1);
        }else if (i==3){//barat (x)(y-1)
            f->setY(y-1);
        }
    }else{
        throw "Tidak ada space";
    }
}

void GameEngine::handleMove(int n){
    List<int> around = lookAround(engi.getX(), engi.getY());
    bool found = false;
    int i = 0;
    while ((!found) && (i<4)){
        if((around.getElmt(i))>=13 && (around.getElmt(i))<=18){
            found = true;
        }else{
            i++;
        }
    }
    if(found){
        throw "Tidak ada Space";
    }else{
        //problem dlm 1 petak ada land ada living things
        int x, y;
        engi.cekPosisi(i, x, y);
        engi.setX(x);
        engi.setY(y);
    }
}

void GameEngine::handleTalk(){
    List<int> around = lookAround(engi.getX(), engi.getY());
    if(around.getElmt(0)>=1 && around.getElmt(0)<=12){
        FarmAnimal* temp = world[engi.getX()-1][engi.getY()]->getAnimal();
        engi.talk(*temp);
    }else if(around.getElmt(1)>=1 && around.getElmt(1)<=12){
        FarmAnimal* temp = world[engi.getX()][engi.getY()+1]->getAnimal();
        engi.talk(*temp);
    }else if(around.getElmt(2)>=1 && around.getElmt(2)<=12){
        FarmAnimal* temp = world[engi.getX()+1][engi.getY()]->getAnimal();
        engi.talk(*temp);
    }else if(around.getElmt(3)>=1 && around.getElmt(3)<=12){
        FarmAnimal* temp = world[engi.getX()][engi.getY()+1]->getAnimal();
        engi.talk(*temp); 
    }
}

void GameEngine::handleMakan(int x, int y){
    world[engi.getX()-1][engi.getY()]->
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
                handleMakan(i,j);
            }
            else if (getID(i,j) == 21 ){ //Jika merupakan truck
                //Ubah keadaan trucknya
                world[i][j]->updateCell();
            }
            //Kasus lain???
        }
    }
        
}
