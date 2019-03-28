#include "Cell/Header/cell.h"
#include "LivingThings/Header/player.h"

class GameEngine{
private:
    Cell** world;
    Player engi;
    int tick;

public:
    GameEngine();
    void handleMove();
    void updateMove(); //nambahTick, ngubah posisi animal, ngubah avaibality truck
    void printWorld();
}