#pragma once
#include <iostream>
#include "BasicString.h"
template <typename Type> 
class List; 


template <typename Type> 

class Node {
private:
	Node<Type>* prev;
	Node<Type>* next;
	Type* value;
	int distance;
public:
	Node();
	Node(Type* value);
	Node(Type* value, int distance);
	Type* GetValue();
	void SetValue(Type* value);

	int getDistance();
	void setDistance(int distance);
	
	Node<Type>* GetPrev();
	Node<Type>* GetNext();

	void SetPrev(Node<Type>* prev);
	void SetNext(Node<Type>* next);

	friend std::ostream& operator<<(std::ostream& os, const Node<Type>& node);
	~Node<Type>();
};