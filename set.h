
template <typename T>
class Set{
    public:
    Set(int maxLength = 20);
    Set(const Set& otherSet);
    Set& operator=(const Set& otherSet);
    ~Set();
    void insert(T element);
    void erase(T element);
    bool isEmpty() const;
    int size();
    int includes(T element);

    private:
    T* tab;
    int length;
    int capacity;
};

template <typename T>
Set<T>::Set(int maxLength){
    tab = new T[maxLength];
    length = 0;
    capacity = maxLength;
}
template <typename T>
Set<T>::Set(const Set& otherSet){
    this->tab = new T[otherSet.capacity];
    this->capacity = otherSet.capacity;
    this->length = otherSet.length;
    if(!otherSet.isEmpty()){
        for(int i=0; i<otherSet.length; i++){
            this->tab[i] = otherSet.tab[i];
        }
    }
}


template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& otherSet){
    if(this != &otherSet){
        this->tab = new T[otherSet.capacity];
        this->capacity = otherSet.capacity;
        this->length = otherSet.length;
        if(!otherSet.isEmpty()){
        for(int i=0; i<otherSet.length; i++){
            this->tab[i] = otherSet.tab[i];
        }
    }
    }
    return *this;
}






template <typename T>
Set<T>::~Set(){
    delete[] tab;
}

template <typename T>
bool Set<T>::isEmpty() const{
    return (length == 0) ? true : false;
}

template <typename T>
int Set<T>::size(){
    return length;
}

template <typename T>
int Set<T>::includes(T element){
    if(isEmpty()) return -1; 
    for(int i=0; i<length; i++){
        if(tab[i] == element){
            return i;
        }
    }
    return -1;
}




template <typename T>
void Set<T>::insert(T element){
    if(includes(element) != -1) return;
    
    if(length == capacity){
        int newLength = 2*capacity;
        T* tempTab = new T[newLength];
        for(int i=0; i<length; i++){
            tempTab[i] = tab[i];
        }
        tempTab[length] = element;
        length++;
        capacity = newLength;
    }
    tab[length] = element;
    length++;
}

template <typename T>
void Set<T>::erase(T element){
    int indexOfElement = includes(element);
    if(indexOfElement == -1) return;
    for(int i=indexOfElement; i<length; i++){
        tab[i] == tab[i+1];
    }
    length--;
}

