#pragma once
#include <iostream>
#include "BasicString.h"
template <typename Type> class List; 


template <typename Type> 

class Node {
private:
	Node<Type>* prev;
	Node<Type>* next;
	Type* value;
	int distance;
public:
	Node();
	Node(Type* value, int distance);
	Type* GetValue();
	void SetValue(Type* value);

	int getDistance();
	void setDistance(int distance);
	
	Node<Type>* GetPrev() const;
	Node<Type>* GetNext() const;

	friend std::ostream& operator<<(std::ostream& os, const Node<Type>& node);
	~Node<Type>();
};