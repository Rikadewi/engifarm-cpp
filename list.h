template <class Type>
class List {
    private:
        Type *data;
    public:
        //ctor-cctor-dtor
        List(); //default Ctor
        List(int); // Ctor dengan parameter
        List(const List<Type>&); // Cctor
        ~List();
        List& operator= (const List<Type>&);

        //Services
        bool isEmpty() const;
        bool isFull() const;
        void add(Type);
        void remove(Type elmt);
        int find(Type elmt);
        Type get(int indeks);

}