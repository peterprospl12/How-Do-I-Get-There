#include "Hashmap.h"
#include "City.h"

const int hash_number = 31;

Hashmap::Hashmap(int x, int y) {
	this->cities = new City[x * y + hash_number]();
	this->size = x * y + hash_number;
}	


unsigned int Hashmap::hash(const char* key) {
	unsigned long long int hashVal = 0;
	int tableSize = 400;

	for (int i = 0; i < std::strlen(key); ++i) {
		hashVal = 31 * hashVal + key[i];
	}

	hashVal %= tableSize;

	return hashVal;
}


void Hashmap::insert(City* newCity) {
	int index = hash(newCity->name.str);
	if (&cities[index] == nullptr) {
		cities[index] = *newCity;
	}
} 

City* Hashmap::find(const char* key) {
	int index = hash(key);
	if (&cities[index] == nullptr) {
		return nullptr;
	}
	else {
		return &cities[index];
	}
}


int Hashmap::getSize() {
	return this->size;
}

int Hashmap::getCurrSize() {
	return this->curr_size;
}

Hashmap::~Hashmap() {
	delete[] cities;
}