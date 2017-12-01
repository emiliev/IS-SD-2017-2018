//
//  Queue.hpp
//  Structures
//
//  Created by Emil Iliev on 12/1/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#include <stdio.h>
#include "Node.hpp"
#include "iostream"
using namespace std;

template <typename T>
class Queue{
    
public:
    
    Queue();
    ~Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    
    void enqueue(T element);
    void dequeue(T& element);
    bool isEmpty();
    T peek();
    size_t size();
    
private:
    
    Node<T>* front;
    Node<T>* rear;
    size_t used;
    
    void copy(const Queue<T>& other);
    void release();
};


template <typename T>
Queue<T>::Queue(){
    
    this->used = 0;
    this->front = 0;
    this->rear = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& other){
    copy(other);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T> &other){
    if ( this != &other){
        release();
        copy(other);
    }
    return *this;
}

template <typename T>
void Queue<T>::enqueue(T element){
    Node<T>* elem = new Node<T>(element,rear);
    front == NULL ? front = elem : rear->pNext = elem;

    rear = elem;
    used++;
}

template <typename T>
Queue<T>::~Queue(){
    release();
}

template <typename T>
bool Queue<T>::isEmpty(){
    
    if(this->used  < 1){
        return false;
    }
    
    return true;
}

template <typename T>
void Queue<T>::dequeue(T& element){
    
    if(isEmpty()){
        
        Node<T>* elem = front;
        front = front->pNext;
        element = elem->data;
        delete elem;
        used--;
    }
}

template <typename T>
T Queue<T>::peek(){
    return used != 0 ? front->data : NULL;
}

template <typename T>
void Queue<T>::release(){
    int elem;
    while (isEmpty()) {
        dequeue(elem);
    }
    front = nullptr;
    rear = nullptr;
}

template <typename T>
void Queue<T>::copy(const Queue<T>& other){

    Node<T>* elem = other.front;
    while (elem) {
        enqueue(elem->data);
        elem = elem->pNext;
    }
}

template <typename T>
size_t Queue<T>::size(){
    return used;
}

