//File : facility.h
#ifndef facility_H
#define facility_H

#include "cell.h"

enum FacilityType {well, mixer, truck};

//facility merupakan turunan dari cell
class Facility : public Cell{
    private:
        FacilityType type;
    public:
        FacilityType getType();
        void setType(FacilityType);
        FarmAnimal* getAnimal();
        void setAnimal(FarmAnimal*);

};

#endif
