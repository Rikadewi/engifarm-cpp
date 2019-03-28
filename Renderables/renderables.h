//File : renderables.h
#ifndef __RENDERABLES_H__
#define __RENDERABLES_H__

class Renderables {
    public:
        //untuk sementara
        //0 jika tembok 
        //1-12 untuk farm animal (ganjil laper, genap kenyang)
        //egg and milk producing? ada brpa?
        //13-18 untuk land (ganjil tdk berumput, genap berumput)
        //19-21 untuk facility
        //19 untuk well
        //20 untuk mixer
        //21 untuk truck
        //22 untuk player
        
        //Method untuk merender suatu objek
        virtual int render()=0;
        //setter
        void setX(int X);//jgn lupa ganti matriks di main
        void setY(int Y); //jgn lupa ganti matriks di main
        //getter 
        int getX();
        int getY();
        bool isLand (int); //liat comment di look around
        bool isAnimal (int); //liat comment di look around
        bool isFacility(int); //liat comment di look around
        
    protected: //knpa ini nggk private aja?
        int PosisiX;
        int PosisiY;

};
#endif