#include "Cell/Header/cell.h"
#include "LivingThings/Header/player.h"
#include "List/list.h"
#include "Cell/Header/facility.h"
#define WORLDSIZE 20

class GameEngine{
    private:
        Cell** world[WORLDSIZE];
        Player engi;      
        int tick;
    public:
        GameEngine();
        List<int> lookAround(int,int); //utara , timur, selatan, barat
        int look(int,int);
        void handleMove(int); //1 = atas, 2 = kanan, 3 = bawah, 4 = kiri
        void handleMoveAnimal();
        void handleTalk();
        void handleInteract();
        void handleKill();
        void handleGrow();
        void updateGame(); //nambahTick, ngubah posisi animal, ngubah avaibality truck
        void printWorld();
        int getID(int,int);
}
