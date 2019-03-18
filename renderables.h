//File : renderables.h
#ifndef __RENDERABLES_H__
#define __RENDERABLES_H__

class Renderables {
    public:
    //Method untuk merender suatu objek
    virtual char render()=0; 

    protected:
        int PosisiX;
        int PosisiY;

};
#endif