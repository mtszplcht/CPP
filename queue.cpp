#include <iostream>
using namespace std;

class QueueOfInts{
    
public:
    virtual void enqueue(int x) = 0;
    virtual int dequeue() = 0;
    virtual bool isEmpty() = 0;
    virtual int peek() const = 0;
    virtual ~QueueOfInts(){}
};

class Queue : public QueueOfInts{

public:
    Queue(int length = 20);
    ~Queue();
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    int peek() const;

private:
    int* tab;
    int maxLength;
    int frontPointer;
    int backPointer;
};

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
