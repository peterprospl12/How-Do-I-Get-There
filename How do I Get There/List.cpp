#include "Node.h"
#include "List.h"
#include "BasicString.h"
#include <iostream>
template <typename Type>

List<Type>::List() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template <typename Type>
void List<Type>::insert(Type data) {
    Node<Type>* section = new Node<Type>(data);
    if (this->head == nullptr) {
        this->head = section;
        this->tail = section;
    }
    else {
        this->tail->next = section;
        section->prev = this->tail;
        this->tail = section;
    }
    this->size++;

}


template <typename Type>
int List<Type>::getSize() {
    return this->size;
}


template <typename Type>
Node<Type>* List<Type>::getHead() const {
    return this->head;
}

template <typename Type>
Node<Type>* List<Type>::getTail() {
    return this->tail;
}


template <typename Type>
std::ostream& operator<<(std::ostream& os, const List<Type>& list) {
    Node<Type>* current = list.getHead();
    while (current != nullptr) {
        os << current->value;
        current = current->next;
        os << std::endl;
    }
    return os;
}



template <typename Type>
void List<Type>::setHead(Node<Type>* newHead) {
    this->head = newHead;
}

template <typename Type>
void List<Type>::setTail(Node<Type>* newTail) {
    this->tail = newTail;
}

template <typename Type>
List<Type>::~List() {

}