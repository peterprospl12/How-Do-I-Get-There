#pragma once
#include <iostream>
#include "BasicString.h"
template <typename Type> 
class List; 


template <typename Type> 

class Node {
public:
	Node<Type>* prev;
	Node<Type>* next;
	Type* value;
	int distance;
public:
	Node();
	explicit Node(Type* value);
	Node(Type* value, int distance);
	Type* GetValue();
	void SetValue(Type* value);

	int getDistance() const;
	void setDistance(int newDistance);
	
	Node<Type>* GetPrev();
	Node<Type>* GetNext();

	void SetPrev(Node<Type>* newPrev);
	void SetNext(Node<Type>* newNext);

	friend std::ostream& operator<<(std::ostream& os, const Node<Type>& node);
	~Node<Type>();
};



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
int Node<Type>::getDistance() const {
	return this->distance;
}


template <typename Type>
void Node<Type>::setDistance(int newDistance) {
	this->distance = newDistance;
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
void Node<Type>::SetPrev(Node<Type>* newPrev) {
	this->prev = newPrev;
}

template <typename Type>
void Node<Type>::SetNext(Node<Type>* newNext) {
	this->next = newNext;
}




template <typename Type>
std::ostream& operator<<(std::ostream& os, const Node<Type>& node) {
	os << node.value << " " << node.distance;
	return os;
}

template <typename Type>
Node<Type>::~Node() {
	delete this->value;
}
