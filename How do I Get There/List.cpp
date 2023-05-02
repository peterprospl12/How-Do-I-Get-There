#include "List.h"
#include "BasicString.h"
#include "City.h"
#include "Node.h"
#include <iostream>
template <typename Type>

List<Type>::List() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template <typename Type>
void List<Type>::insert(Type* data, int distance) {

    Node<Type>* section = new Node<Type>(data, distance);
    if (this->head == nullptr) {
        this->head = section;
        this->tail = section;
    }
    else {
        this->tail->SetNext(section);
        section->SetPrev(this->tail);
        this->tail = section;
    }
    this->size++;

}


template <typename Type>
int List<Type>::getSize() const {
    return this->size;
}


template <typename Type>
Node<Type>* List<Type>::getHead() const {
    return this->head;
}

template <typename Type>
Node<Type>* List<Type>::getTail() const{
    return this->tail;
}



template <typename Type>

void List<Type>::drawList() {
	Node<Type>* current = this->head;
    while (current != nullptr) {
		std::cout << current->GetValue()->getName() << ", dist: " << current->getDistance() << std::endl;
		current = current->GetNext();
	}
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
