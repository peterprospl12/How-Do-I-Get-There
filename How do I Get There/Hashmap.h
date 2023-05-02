#pragma once
#include <iostream>
#include "Queue.h"

class City;

class Hashmap {
private:
	Queue<qCity>* cities;
	int curr_size = 0;
	int size = 0;
public: 
	Hashmap();
	Hashmap(int x, int y);
	
	unsigned int hash(const char* key) const;
	
	int getSize() const;
	int getCurrSize() const;
	
	void insert(City* newCity);
	
	City* find(const char* key);
	void delayedDestructor();
	
	~Hashmap();
};