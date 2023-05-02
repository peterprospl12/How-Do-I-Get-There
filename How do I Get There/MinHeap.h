#pragma once
#include "Vector.h"
#include "City.h"


class MinHeap {
public:
	Vector<City*> cities;
	Vector<int> distances;
	int size;
	
public:	

	MinHeap() {
		this->size = 0;
	}
	void heapifyUp(int index) {
		int parentIndex = parent(index);
		while (index > 0 && distances[index] < distances[parentIndex]){

			distances.swap(index, parentIndex);
			cities.swap(index, parentIndex);

			index = parentIndex;
			parentIndex = parent(index);
		}
	}
	void insert(City* city, int distance) {
		cities.push_back(city);
		distances.push_back(distance);
		this->size++;
		heapifyUp(size - 1);
	}
	
	void erase(int index) {
		
		distances.swap(index, size - 1);
		cities.swap(index, size - 1);
		distances.popBack();
		cities.popBack();
		size--;
		if (index == size) {
			return;
		}
		int parentIndex = parent(index);
		if (index > 0 && distances[index] < distances[parentIndex]) {
			heapifyUp(index);
		}
		else {
			heapifyDown(index);
		}
	}

	void heapifyDown(int index) {
		int smallest = index;
		int leftChild = left(index);
		int rightChild = right(index);

		while (leftChild < size) {
			if (distances[leftChild] < distances[smallest]) {
				smallest = leftChild;
			}

			if (rightChild < size && distances[rightChild] < distances[smallest]) {
				smallest = rightChild;
			}

			if (smallest == index) {
				break;
			}

			distances.swap(index, smallest);
			cities.swap(index, smallest);

			index = smallest;
			leftChild = left(index);
			rightChild = right(index);
			smallest = index;
		}
	}

	bool empty() const {
		return this->size == 0;
	}

	static int parent(int index) {
		return (index - 1) / 2;
	}
	
	static int left(int index) {
		return (2 * index + 1);
	}

	static int right(int index) {
		return (2 * index + 2);
	}
};