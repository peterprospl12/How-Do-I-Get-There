#include <iostream>
#include "Node.h"
#include "BasicString.h"

template <typename Type>
Node<Type>::Node() {
    this->prev = nullptr;
    this->next = nullptr;
    this->value = nullptr;
    this->distance = 0;
}

template <typename Type>

Node<Type>::Node(Type* value) {
	this->prev = nullptr;
	this->next = nullptr;
	this->value = value;
	this->distance = 0;
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
Node<Type>* Node<Type>::GetPrev() {
	return this->prev;
}

template <typename Type>
Node<Type>* Node<Type>::GetNext() {
	return this->next;
}

template <typename Type>
void Node<Type>::SetPrev(Node<Type>* prev) {
	this->prev = prev;
}

template <typename Type>
void Node<Type>::SetNext(Node<Type>* next) {
	this->next = next;
}




template <typename Type>
std::ostream& operator<<(std::ostream& os, const Node<Type>& node) {
	os << node.value << " " << node.distance;
	return os;
}

template <typename Type>
Node<Type>::~Node() {

}
