#include "Vector.h"
template <typename Type>
class Stack {
private:
	Vector<Type> data;
	int size;
public:
	
	Stack() {
		this->size = 0;
	}
	
	void push(const Type& value) {
		data.push_back(value);
		this->size++;
	}
	
	void pop() {
		data.popBack();
		this->size--;
	}
	
	Type top() {
		return data[size - 1];
	}
	
	int getSize() const {
		return this->size;
	}
	
	bool isEmpty() const {
		return this->size == 0;
	}
	
	~Stack() {
	}



};