#include "gameengine.h"

GameEngine::GameEngine(){
    tick = 0;
    for(int i=0;i<WORLDSIZE;i++){
        world[i]=new Cell*[WORLDSIZE];
    }
}

int GameEngine::look(int i, int j){
    if((getID(i,j)>=1 && getID(i,j)<=12) || (getID(i,j)>=19 && getID(i,j)<=22)){
            return world[i][j]->render();
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
        if(around.getElmt(0)>=1 && around.getElmt(0)<=){
            FarmAnimal* temp = world[engi.getX()][engi.getY()+1]->getAnimal();
            
        }
    }
    

}

void GameEngine::handleMove(int n){
    List<int> around = lookAround(engi.getX(), engi.getY());
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

void GameEngine::handleTalk(){
    List<int> around = lookAround(engi.getX(), engi.getY());
    if(around.getElmt(0)>=1 && around.getElmt(0))
    engi.talk();
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
            if(getID(i,j) == ) {

            }



        }
    }
        
}