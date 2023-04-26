#pragma once

template <typename Type>
class Vector {
private:
	Type** data;
	int capacity;
	int size;
public:
	Vector() {
		this->data = new Type*[1];
		this->capacity = 1;
		this->size = 0;
	}
	~Vector() {

	}
	int getSize() {
		return this->size;
	}
	bool isEmpty() {
		return this->size == 0;
	}
	void push_back(Type* element) {
		if (this->size >= this->capacity) {
			this->reserve(this->capacity * 2);
		}
		this->data[this->size] = element;
		this->size++;
	}

	void reserve(int newCapacity) {
		if (newCapacity > this->capacity) {
			this->capacity = newCapacity;
			Type** temp = new Type*[this->capacity];
			for (int i = 0; i < this->size; i++) {
				temp[i] = this->data[i];
			}
			delete[] this->data;
			this->data = temp;
		}
	}

	void popBack() {
		if (size > 0) {
			this->data[size - 1] = nullptr;
			this->size--;
		}
	}

	Type* operator[](int index) {
		if (index >= 0 && index < size) {
			return data[index];
		}
		return nullptr;
	}




};