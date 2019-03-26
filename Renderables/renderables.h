//File : renderables.h
#ifndef __RENDERABLES_H__
#define __RENDERABLES_H__

class Renderables {
    public:
        //Method untuk merender suatu objek
        virtual char render()=0;
        //setter
        void setX(int X);//jgn lupa ganti matriks di main
        void setY(int Y); //jgn lupa ganti matriks di main
        //getter 
        int getX();
        int getY();

    protected: //knpa ini nggk private aja?
        int PosisiX;
        int PosisiY;

};
#endif