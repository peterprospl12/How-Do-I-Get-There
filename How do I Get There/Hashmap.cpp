#include "Hashmap.h"
#include <iostream>
#include "City.h"

const int hash_number = 31;

Hashmap::Hashmap() {
	this->cities = nullptr;
	this->size = 0;
}

Hashmap::Hashmap(int x, int y) {
	this->cities = new Queue<qCity>[x * y + hash_number]();
	this->size = x * y + hash_number;
}	


unsigned int Hashmap::hash(const char* key) const{
	unsigned long long int hashVal = 0;
	int tableSize = size;

	for (int i = 0; i < std::strlen(key); ++i) {
		hashVal = 31 * hashVal + key[i];
	}

	hashVal = hashVal % tableSize;

	return hashVal;
}


void Hashmap::insert(City* newCity) {
	int index = hash(newCity->getName().str);
	
	cities[index].insert(newCity);
	this->curr_size++;
}

City* Hashmap::find(const char* key) {
	int index = hash(key);
	
	
		qCity* tempNode = cities[index].getHead();
		while (tempNode->city->getName() != key) {
			tempNode = tempNode->next;
		}
		return tempNode->city;
	
}


int Hashmap::getSize() const{
	return this->size;
}

int Hashmap::getCurrSize() const{
	return this->curr_size;
}

void Hashmap::delayedDestructor() {

	delete[] cities;
}


Hashmap::~Hashmap() {
	
}