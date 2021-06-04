
using namespace std;

class EmptyCollection : public exception {
    public:
    const char* getInfo(){return "EmptyCollection.";}
};




template <typename T>
class Vector{
    public:
    Vector(int startingCapacity = 10);
    ~Vector();
    void push_back(T element);
    void pop_back();
    T getElement(int index)noexcept(false);
    bool isEmpty() const;
    void print();
    int getCapacity() const;
    int getLength() const;

    private:
    T* tab;
    int capacit;
    int length;
};

template <typename T>
Vector<T>::Vector(int startingCapacity){
    tab = new T[10];
    capacit = startingCapacity;
    length = 0;
}
template <typename T>
Vector<T>::~Vector(){ delete[] tab; }

template <typename T>
void Vector<T>::push_back(T element){
    if(length == capacit){
        int newCapacity = capacit * 2;
        T* tempTab = new T[newCapacity];
        for(int i=0; i<capacit; i++){
            tempTab[i] = tab[i];
        }
        delete[] tab;
        tab = tempTab;
        capacit = newCapacity;
    }
    tab[length] = element;
    length++;
}

template <typename T>
T Vector<T>::getElement(int index) noexcept(false){
    if(index <= length){
        return tab[index];
    }
    if(isEmpty()) throw EmptyCollection();
}
template <typename T>
void Vector<T>::pop_back(){
    if(isEmpty()){
        cout << "Stack is empty. There is nothing to be popped." <<endl;
    }else{
        length--;
    }
}



template <typename T>
bool Vector<T>::isEmpty() const{
    return length == 0 ? true : false;
}

template <typename T>
void Vector<T>::print(){
    for(int i=0; i<length; i++){
        cout << tab[i] << " ";
    }
    cout << endl;
}

template <typename T>
int Vector<T>::getCapacity() const{
    return capacit;
}

template <typename T>
int Vector<T>::getLength() const{
    return length;
}
