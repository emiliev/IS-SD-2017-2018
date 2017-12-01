//
//  Stack.hpp
//  Structures
//
//  Created by Emil Iliev on 12/1/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#include <stdio.h>
#include "Node.hpp"

template <typename T>
class LinkedStack{
    
public:
    LinkedStack();
    ~LinkedStack();
    LinkedStack& operator=(LinkedStack const &other);
    LinkedStack(LinkedStack const &other);
    
    void push(T element);
    bool pop(T& element);
    bool isEmpty();
    T peek();
private:
    
    void init();
    void destroy();
    void copyFrom(LinkedStack const &other);
    Node<T>* pTop;
    size_t used;
};

template <typename T>
LinkedStack<T>::LinkedStack(){
    
    init();
}

template <typename T>
LinkedStack<T>::~LinkedStack(){
    
    destroy();
}

template <typename T>
LinkedStack<T>::LinkedStack(LinkedStack<T> const &other){
    
    init();
    copyFrom(other);
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(LinkedStack<T> const &other){
    
    if(this != &other){
        destroy();
        copyFrom(other);
    }
    
    return *this;
}

template <typename T>
void LinkedStack<T>::push(T element){
    
    Node<T>* elem = new Node<T>(element, pTop);
    pTop = elem;
    used++;
}

template <typename T>
bool LinkedStack<T>::pop(T& element){
    
    if(used == 0){
        return false;
    }
    
    element = pTop->data;
    
    Node<T>* currentElement = pTop;
    pTop = pTop->pNext;
    delete currentElement;
    used--;
    
    return true;
}

template <typename T>
T LinkedStack<T>::peek(){
    
    return pTop->Data;
}

template <typename T>
bool LinkedStack<T>::isEmpty(){
    
    if(used == 0){
        return true;
    }
    
    return false;
}

template <typename T>
void LinkedStack<T>::copyFrom(const LinkedStack<T> &other){
    
    Node<T> *newElem, *oldElem;
    
    pTop = new Node<T>(other.pTop->data, other.pTop->pNext);
    newElem = pTop;
    oldElem = other.pTop->pNext;
    
    while (oldElem) {
        
        newElem->pNext = new Node<T>(oldElem->data);
        newElem = newElem->pNext;
        oldElem = oldElem->pNext;
    }
    
    used = other.used;
}
template <typename T>
Node<T>* copy(Node<T>*& node){
    if (!node){ return NULL; }
    return node;
}


template <typename T>
void LinkedStack<T>::destroy(){
    
    Node<T>* p;
    while (pTop) {
        
        p = pTop;
        pTop = pTop->pNext;
        delete p;
    }
    
    init();
}

template <typename T>
void LinkedStack<T>::init(){
    
    pTop = 0;
    used = 0;
}

