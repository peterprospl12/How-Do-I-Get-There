#pragma once
#include "City.h"
struct qNode {
	int posX;
	int posY;
	int distance;
	qNode* next;
};

struct qCity {
	City* city;
	qCity* next;
};

template <typename Type>
class Queue {
private:
	Type* head;
	Type* tail;
	int size;
public:

	Queue() {
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}

	void insert(int posX, int posY, int distance) {
		qNode* section = new qNode();

		section->posX = posX;
		section->posY = posY;
		section->distance = distance;
		section->next = nullptr;

		if (this->tail == nullptr) {
			this->head = section;
			this->tail = section;
		}
		else {
			this->tail->next = section;
			this->tail = section;
		}
		this->size++;
	}

	void insert(City* city) {
		qCity* section = new qCity();
		section->city = city;
		section->next = nullptr;
		if (this->tail == nullptr) {
			this->head = section;
			this->tail = section;
		}
		else {
			this->tail->next = section;
			this->tail = section;
		}
		this->size++;
	}



	void pop() {
		if (this->head == nullptr) {
			return;
		}
		Type* temp = this->head;
		this->head = this->head->next;
		if (this->head == nullptr) {
			this->tail = nullptr;
		}
		delete temp;
		this->size--;
	}

	int getSize() {
		return this->size;
	}


	Type* getHead() {
		return this->head;
	}

	Type* getTail() {
		return this->tail;
	}

	void setHead(Type* newHead) {
		this->head = newHead;
	}

	void setTail(Type* newTail) {
		this->tail = newTail;
	}

	~Queue() {
		while (this->head != nullptr) {
			Type* temp = this->head;
			this->head = this->head->next;
			delete temp;
		}
	}
};