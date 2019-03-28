//File : cell.h
#ifndef CELL_H
#define CELL_H

enum Place {land, facility}

class Cell{
    private:
        Place place;
    public:
        virtual int render() = 0;
        Place getPlace();
        void setPlace(Place);
};

#endif
