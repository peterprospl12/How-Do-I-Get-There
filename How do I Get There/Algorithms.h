#pragma once
#include <iostream>
#include "Queue.h"
#include "BasicString.h"
#include "Hashmap.h"
#include "List.cpp"
#include "City.h"
#include "Stack.h"
#include "MinHeap.h"

void djikstra_algorithm(Hashmap world, BasicString start, BasicString end, bool showPath);

bool checkForMove(char** map, int mapWidth, int mapHeight, int currX, int currY);
void checkForBranches(Queue<qNode>& q, char** map, int distance, int mapWidth, int mapHeight, int currX, int currY, bool** visited);

void findNeighbours(char** map, Hashmap& world, BasicString** nameMap, int width, int height, City* city);
void processMap(Queue<qCity>& cities, BasicString** nameMap, char** map, int mapWidth, int mapHeight, Hashmap& world);

void readFlights(Hashmap& world);
void readQueries(Hashmap& world);
