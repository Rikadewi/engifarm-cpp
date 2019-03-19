template <class T>
class LinkedList{
public:
    LinkedList();
    int find(T);
    bool isEmpty();
    void add(T);
    void remove(T);
    int get(int);
private:
    T *data;
    
}