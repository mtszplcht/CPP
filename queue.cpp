#include <iostream>
using namespace std;


Queue::Queue(int length){
    tab = new int[length];
    maxLength = length;
    frontPointer = 0;
    backPointer = 0;
    cout<<"Queue has been constructed. Max length = "<<maxLength<<endl;
}
Queue::~Queue(){
    delete[] tab;
    cout<<"Queue has been deleted."<<endl;
}
void Queue::enqueue(int x){
    if(backPointer == (maxLength-1)){
        cout<<"Queue is full."<<endl;
    }else{
        tab[backPointer] = x;
        backPointer++;
    }
}
int Queue::dequeue(){
    if(isEmpty()){
        return 0;
    }else{
        int frontValue = tab[frontPointer];
        for(int i=0; i<backPointer; i++){
            tab[i] = tab[i+1];
        }
        backPointer--;
        return frontValue;
    }
}
bool Queue::isEmpty(){
    if(frontPointer == backPointer){
        cout<<"Queue is empty."<<endl;
        return true;
    }else{
        return false;
    }
}
int Queue::peek() const {
    if(frontPointer == backPointer){
        cout<<"Queue is empty."<<endl;
        return 0;
    }else{
        return tab[frontPointer];
    }
}
