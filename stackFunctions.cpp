#include <iostream>
#include "stack.h"
using std::cout;
using std::endl;


Stack::Stack(int length){
    tab = new int[length];
    top = -1;
    maxLength = length;
    stackLength = 0;
    cout<<"Stack is created. Max length = "<<maxLength<<endl;
}
Stack::~Stack(){
    delete[] tab; 
    cout<<"The stack has been deleted."<<endl;
}

int Stack::pop(){
    if(top < 0){
        cout<<"There is nothing to pop.";
        return 0;
    }else{
        int number = tab[top--];
        stackLength--;
        return number;
    } 
}
void Stack::push(int x){
    if(top >= maxLength - 1){
        cout<<"Stack overflow"<<endl;
    }else{
        tab[++top] = x;
        stackLength++;
        cout<<"The element: "<<x<<" has been pushed."<<endl;
    }
}
bool Stack::isEmpty(){
    if(top < 0) return true;
    else return false;
}
int Stack::size(){
    return top;
}
int Stack::peek() const {
    if(top < 0) {
        cout<<"Stack is empty."<<endl;
        return 0;
    }else{
        int peek = tab[top];
        return peek;
    }
}
