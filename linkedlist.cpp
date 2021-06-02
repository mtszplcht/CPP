#include <iostream>

using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node* next;
};

template <typename T>
class LinkedList{
    public:
    LinkedList();
    void addNode(T data);
    void display();
    void insert(int position, T data);
    void add_at_begining(T data);

    private:
    Node<T> *head, *tail;
};

template <typename T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void LinkedList<T>::addNode(T data){
    Node<T> *newNode = new Node<T>();
    newNode->data = data;
    newNode->next = nullptr;

    if(head == nullptr){
        head = newNode;
        tail = newNode;
        newNode = nullptr;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void LinkedList<T>::display(){
    Node<T> *ptr = head;
    while(ptr != nullptr){
        cout<<ptr->data <<" ";
        ptr = ptr->next;
    }
}

template <typename T>
void LinkedList<T>::insert(int position, T data){
    Node<T> *newNode = new Node<T>();
    newNode->data = data;
    Node<T> *current = head;
    Node<T> *previous;

    for(int i=1; i<position; i++){
        previous = current;
        current = current->next;
    }
    previous->next = newNode;
    newNode->next = current;
}

template <typename T>
void LinkedList<T>::add_at_begining(T data){
    Node<T> *newNode = new Node<T>();
    newNode->data = data;
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
}


