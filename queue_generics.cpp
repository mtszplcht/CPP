#include <iostream>
using namespace std;

class EmptyCollection : public exception {
    public:
    void info(){cout<<"Collection is empty!"<<endl;}
};



template <typename T>
class Queue{

public:
    Queue(int length = 20);
    ~Queue();
    void enqueue(T x);
    T dequeue();
    bool isEmpty();
    T peek() const;

private:
    T* tab;
    int maxLength;
    int frontPointer;
    int backPointer;
};

template <typename T>
Queue<T>::Queue(int length){
    tab = new T[length];
    maxLength = length;
    frontPointer = 0;
    backPointer = 0;
}

template <typename T>
Queue<T>::~Queue(){
     delete[] tab;
 }

 template <typename T>
 void Queue<T>::enqueue(T x){
     if(backPointer == maxLength-1){
        cout<<"Queue is full."<<endl;
     }else{
        tab[backPointer] = x;
        backPointer++;
     }
 }

 template <typename T>
 T Queue<T>::dequeue(){
     if(isEmpty()){
         throw EmptyCollection();
     }else{
         T firstElement = tab[frontPointer];
         for(int i=0; i<backPointer; i++){
             tab[i] = tab[i+1];
         }
         backPointer--;
         return firstElement;
     }
 }


 template <typename T>
 bool Queue<T>::isEmpty(){
     if(frontPointer == backPointer){
         return true;
     }else{
         return false;
     }
 }

template <typename T>
T Queue<T>::peek() const{
    if(isEmpty()){
        throw EmptyCollection();
    }else{
        return tab[frontPointer];
    }
}



