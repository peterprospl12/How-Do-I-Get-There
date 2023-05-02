#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Algorithms.h"

using std::cout;
using std::cin;
using std::endl;


int main()
{
	Queue<qCity> cities;

	char** map;
	int mapWidth, mapHeight;
	
	std::cin >> mapWidth >> mapHeight;
	
	Hashmap world(mapWidth, mapHeight);
	map = new char*[mapHeight];
	
	for (int i = 0; i < mapHeight; i++) {
		map[i] = new char[mapWidth];
	}

	
	BasicString** nameMap = new BasicString* [mapHeight];
	for (int i = 0; i < mapHeight; i++) {
		nameMap[i] = new BasicString[mapWidth];
	}

	processMap(cities, nameMap, map, mapWidth, mapHeight, world);

	int size = cities.getSize();
	for (int i = 0; i < size; i++) {
		City* kk = cities.getHead()->city;
		findNeighbours(map, world, nameMap, mapWidth, mapHeight, kk);
		cities.pop();
	}

	for (int i = 0; i < mapHeight; i++) {
		delete[] nameMap[i];
		delete[] map[i];
	}
	delete[] nameMap;
	delete[] map;


	readFlights(world);
	readQueries(world);

	world.delayedDestructor();

	return 0;
}
