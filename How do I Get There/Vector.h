#pragma once

template <typename Type>
class Vector {
private:
	Type* data;
	int capacity;
	int size;
public:
	Vector() {
		this->data = new Type[1];
		this->capacity = 1;
		this->size = 0;
	}
	explicit Vector(int capacity) {
		this->data = new Type[capacity];
		this->capacity = capacity;
		this->size = 0;
	}
	~Vector() {
		delete[] this->data;
	}
	int getSize() const {
		return this->size;
	}
	
	bool isEmpty() const {
		return this->size == 0;
	}
	void push_back(const Type& element) {
		if (this->size >= this->capacity) {
			this->reserve(this->capacity * 2);
		}
		this->data[this->size] = element;
		this->size++;
	}

	void reserve(int newCapacity) {
		if (newCapacity > this->capacity) {
			this->capacity = newCapacity;
			Type* temp = new Type[this->capacity];
			for (int i = 0; i < this->size; i++) {
				temp[i] = this->data[i];
			}
			delete[] this->data;
			this->data = temp;
		}
	}

	void popBack() {
		if (size > 0) {
			this->data[size - 1] = Type();
			this->size--;
		}
	}

	Type operator[](int index) {
		if (index >= 0 && index < size) {
			return data[index];
		}
		return Type();
	}

	void setValue(int index, Type value) {
		if (index >= 0 && index < size) {
			data[index] = value;
		}
	}


	void swap(int first, int second) {
		if (first >= 0 && second >= 0 && first < size && second < size) {
			Type temp = data[first];
			data[first] = data[second];
			data[second] = temp;
		}
	}

	


};