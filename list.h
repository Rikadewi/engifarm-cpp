//File: list.h
#ifndef __LIST_H__
#define __LIST_H__

template <class Type>
class List {
    private:
        Type *data;
        int size;
        int Neff;
    public:
        //ctor-cctor-dtor
        List(); //default Ctor
        List(int); // Ctor dengan parameter
        List(const List<Type>&); // Cctor
        ~List();
        List& operator= (const List<Type>&);

        //Services
        int getNeff();
        int getSize();
        bool isEmpty() const;
        bool isFull() const;
        void add(Type);
        void remove(Type elmt);
        int find(Type elmt); //jika tidak ditermukan kembalikan -1
        Type get(int indeks);

};

#endif