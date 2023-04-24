#pragma once
#include "Node.h"
#include "BasicString.h"
#include <iostream>

template <typename Type>

class List {
private:
    Node<Type>* head;
    Node<Type>* tail;
    int size;
public:
    List();
    void insert(Type data);
    
    int getSize();
    
    Node<Type>* getHead() const;
    Node<Type>* getTail();
    
    
    void setHead(Node<Type>* newHead);
    void setTail(Node<Type>* newTail);

    ~List();

};