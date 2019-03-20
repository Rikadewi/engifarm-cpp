//File : renderables.h
#ifndef __RENDERABLES_H__
#define __RENDERABLES_H__

class Renderables {
    public:
    //Method untuk merender suatu objek
    virtual char render()=0;
    //setter
    void setX(int X);
    void setY(int Y);
    //getter 
    int getX();
    int getY();

    protected:
        int PosisiX;
        int PosisiY;

};
#endif