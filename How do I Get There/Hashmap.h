#pragma once

#include "Node.h"
#include "City.h"

class Hashmap {
private:
	City* cities;
	int curr_size = 0;
	int size = 0;
public:
	Hashmap(int x, int y);
	unsigned int hash(const char* key);
	int getSize();
	int getCurrSize();
	void insert(City* newCity);
	City* find(const char* key);
	
	~Hashmap();
};