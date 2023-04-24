#include <iostream>
#include "Node.h"
#include "BasicString.h"
template <typename Type>
Node<Type>::Node() {
    this->prev = nullptr;
    this->next = nullptr;
    this->value = nullptr;
    this->distance = 0;
    this->neighbours = nullptr;
}

template <typename Type>
Node<Type>::Node(Type* value, int distance) {
	this->prev = nullptr;
	this->next = nullptr;
	this->value = value;
    this->distance = distance;
}

template <typename Type>
Type* Node<Type>::GetValue() {
	return this->value;
}


template <typename Type>
void Node<Type>::SetValue(Type* value) {
	this->value = value;
}


template <typename Type>
int Node<Type>::getDistance() {
	return this->distance;
}


template <typename Type>
void Node<Type>::setDistance(int distance) {
	this->distance = distance;
}


template <typename Type>
Node<Type>* Node<Type>::GetPrev() const {
	return this->prev;
}


template <typename Type>
Node<Type>* Node<Type>::GetNext() const {
	return this->next;
}

template <typename Type>
std::ostream& operator<<(std::ostream& os, const Node<Type>& node) {
	os << node.value << " " << node.distance;
	return os;
}

template <typename Type>
Node<Type>::~Node() {

}
