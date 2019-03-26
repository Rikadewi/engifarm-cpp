//File: livingthings.h
#ifndef __LIVINGTHINGS_H__
#define __LIVINGTHINGS_H__

#include "../list.h"
#include "renderables.h"

class LivingThings : public Renderables {
    public:
        virtual void Move();
        bool isLand (int); //liat comment di look around
        bool isAnimal (int); //liat comment di look around
        bool isFacility(int); //liat comment di look around
    protected:
        //untuk sementara
        //0 jika tembok 
        //1-12 untuk farm animal (ganjil laper, genap kenyang)
        //egg and milk producing? ada brpa?
        //13-18 untuk land (ganjil tdk berumput, genap berumput)
        //19-21 untuk facility
        //urutan: utara, timur, selatan, barat
        //problem: dlm 1 posisi bs ada land, ada living things
        List <int> lookAround(); //diubah jadi method
};

#endif
