#include "gameengine.h"

GameEngine::GameEngine(){
    tick = 0;
    for(int i=0;i<WORLDSIZE;i++){
        world[i]=new Cell*[WORLDSIZE];
    }
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
    //Cek atas
    
    if(around.getElmt(0)!=0){
        if(around.getElmt(0)>=1 && around.getElmt(0)<=10){ //Animal penghasil egg dan milk
            FarmAnimal* temp = world[engi.getX()-1][engi.getY()]->getAnimal();
            engi.interact(*temp);            
            
        }
    }
    

}

void GameEngine::handleMoveAnimal(){
    
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
                handleMoveAnimal();
            }
            else if (getID(i,j) == 21 ){ //Jika merupakan truck
                //Ubah keadaan trucknya
            }
            //Kasus lain???
        }
    }
        
}