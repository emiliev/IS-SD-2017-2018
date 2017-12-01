//
//  Node.hpp
//  Structures
//
//  Created by Emil Iliev on 12/1/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

template <typename T>
class Node{
    
public:
    Node<T>* pNext;
    T data;
    
    Node(T data, Node<T>* p = nullptr){
        this->data = data;
        this->pNext = p;
    }
};

#endif /* Node_hpp */
