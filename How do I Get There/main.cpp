#include <iostream>
#include "BasicString.h"
#include "Hashmap.h"
#include <list>
#include "List.cpp"
#include "Node.cpp"
#include "City.h"
#include "Queue.h"
using namespace std;




void djikstra_algorithm(Hashmap world, BasicString start, BasicString end) {
	City* from = world.find(start.str);
	City* to = world.find(end.str);
	int size = world.getCurrSize();
	bool* visited = new bool[size];
	int* distance = new int[size];

	for (int i = 0; i < size; i++) {
		visited[i] = false;
		distance[i] = INT_MAX;
	}

	distance[from->getId()] = 0;

	for (int i = 0; i < size - 1; i++) {
		int min_dist = INT_MAX;
		City* current = nullptr;

		// ZnajdŸ najbli¿sze miasto, które nie zosta³o jeszcze odwiedzone
		for (Node<City>* neighborNode = from->getNeighboursList().getHead(); neighborNode != nullptr; neighborNode = neighborNode->GetNext()) {
			int neighborId = neighborNode->GetValue()->getId();
			if (!visited[neighborId] && distance[from->getId()] + neighborNode->getDistance() < distance[neighborId]) {
				distance[neighborId] = distance[from->getId()] + neighborNode->getDistance();
			}

			if (!visited[neighborId] && distance[neighborId] < min_dist) {
				min_dist = distance[neighborId];
				current = neighborNode->GetValue();
			}
		}

		// Jeœli nie uda³o siê znaleŸæ kolejnego miasta, koñczymy przetwarzanie
		if (current == nullptr) {
			break;
		}

		visited[current->getId()] = true;
		from = world.find(current->getName().str);
	}

	std::cout << "Najkrotsza droga z " << start << " do " << end << " wynosi: " << distance[to->getId()] << endl;
}







bool checkForMove(char** map, int mapWidth, int mapHeight, int& currX, int& currY, bool** visited) {
	if (currY + 1 < mapHeight) {
		if ((map[currY + 1][currX] == '#' || map[currY + 1][currX] == '*') && visited[currY + 1][currX] == false) {
			currY += 1;
			return true;


		}
	}
	if (currY - 1 >= 0) {
		if ((map[currY - 1][currX] == '#' || map[currY - 1][currX] == '*') && visited[currY - 1][currX] == false) {
			currY -= 1;
			return true;

		}
	}
	if (currX + 1 < mapWidth) {
		if ((map[currY][currX + 1] == '#' || map[currY][currX + 1] == '*') && visited[currY][currX + 1] == false) {
			currX += 1;
			return true;

		}
	}
	if (currX - 1 >= 0) {
		if ((map[currY][currX - 1] == '#' || map[currY][currX - 1] == '*') && visited[currY][currX - 1] == false) {
			currX -= 1;
			return true;
		}
	}
	return false;
}

int checkForBranches(char** map, int mapWidth, int mapHeight, int& currX, int& currY, bool** visited) {
	int counter = 0;
	if (currY + 1 < mapHeight) {
		if ((map[currY + 1][currX] == '#' || map[currY + 1][currX] == '*') && visited[currY + 1][currX] == false) {
			counter++;

		}
	}
	if (currY - 1 >= 0) {
		if ((map[currY - 1][currX] == '#' || map[currY - 1][currX] == '*') && visited[currY - 1][currX] == false) {
			counter++;

		}
	}
	if (currX + 1 < mapWidth) {
		if ((map[currY][currX + 1] == '#' || map[currY][currX + 1] == '*') && visited[currY][currX + 1] == false) {
			counter++;

		}
	}
	if (currX - 1 >= 0) {
		if ((map[currY][currX - 1] == '#' || map[currY][currX - 1] == '*') && visited[currY][currX - 1] == false) {
			counter++;
		}
	}
	return counter;
}


void findNeighbours(char** map, Hashmap& world, BasicString** nameMap, int width, int height, City* city) {
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	int distance = 0;
	int y = city->getPosY();
	int x = city->getPosX();
	bool** visited = new bool* [height];
	bool** found = new bool* [height];
	for (int i = 0; i < height; i++) {
		visited[i] = new bool[width];
		found[i] = new bool[width];
		for (int j = 0; j < width; j++) {
			visited[i][j] = false;
			found[i][j] = false;
		}
	}
	Queue<qNode> q;
	q.insert(x, y, distance);
	visited[y][x] = true;
	int ways = checkForBranches(map, width, height, x, y, visited);
	if (ways > 1) {
		q.insert(x, y, distance);

	}
	while (checkForMove(map, width, height, x, y, visited)) {
		distance++;
		visited[y][x] = true;
		ways = checkForBranches(map, width, height, x, y, visited);
		if(ways > 1){
			q.insert(x, y, distance);
		}
	    if(map[y][x] == '*'){
			
			city->getNeighboursList().insert(world.find(nameMap[y][x].str), distance);
			
			visited[y][x] = false;
			q.pop();
			if (q.getSize() == 0) {
				break;
			}
			qNode* temp = q.getHead();
			x = temp->posX;
			y = temp->posY;
			distance = temp->distance;
		}
		
	}
}

int main()
{
	Queue<qCity> cities;
	int citiesCount = 0;


	char** map;
	int mapWidth, mapHeight;
	std::cin >> mapWidth >> mapHeight;
	Hashmap world(mapWidth, mapHeight);
	map = new char*[mapHeight];
	for (int i = 0; i < mapHeight; i++) {
		map[i] = new char[mapWidth];
	}

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			char c = getchar();
			if (c == '\n') {
				j--;
				continue;
			}

			map[i][j] = c;
		}
	}

	
	BasicString** nameMap = new BasicString* [mapHeight];
	for (int i = 0; i < mapHeight; i++) {
		nameMap[i] = new BasicString[mapWidth];
	}

	int currCityX, currCityY;
	char c;
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			c = map[i][j];
			
			if (c == '*') {
				char currCity[15];
				currCityX = j;
				currCityY = i;
				
				int moves[8][2] = { {-1,0}, {-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1, 1} };
				int currMove = 0;
				int currY = i;
				int currX = j;
				while (currMove < 8) {
					
					currY += moves[currMove][1];
					currX += moves[currMove][0];
					if (currY >= 0 && currY < mapHeight && currX >= 0 && currX < mapWidth) {
						c = map[currY][currX];
					}
					
					
					if (c != '#' && c != '.' && c != '*') {
						break;
					}
					
					currY = i;
					currX = j;
					currMove++;
				}
				
				while (currX - 1 >= 0 && map[currY][currX - 1] != '#' && map[currY][currX - 1] != '.' && map[currY][currX - 1] != '*') {
					currX--;
				}
				int nameCounter = 0;
				while (currX  < mapWidth && map[currY][currX] != '#' && map[currY][currX] != '.' && map[currY][currX] != '*') {
					currCity[nameCounter++] = map[currY][currX];
					map[currY][currX] = '.';
					currX++;
				}
				currCity[nameCounter] = '\0';
				
				City* founded = new City(currCity, currCityX, currCityY, world.getCurrSize());
				nameMap[currCityY][currCityX] = currCity;
				world.insert(founded);
				
				
				cities.insert(founded);
				
				
				
				
				nameMap[currCityY][currCityX] = currCity;
			}

		}
	}
	int size = cities.getSize();
	for (int i = 0; i < size; i++) {
		City* kk = cities.getHead()->city;
		findNeighbours(map, world, nameMap, mapWidth, mapHeight, kk);
		cities.pop();
	}

	djikstra_algorithm(world, "KRAKOW", "GDANSK");


	//int flights, queries, type;
	//cin >> flights;
	//if (flights > 0) {
	//	//BasicString* from = new BasicString[flights];
	//	//BasicString* to = new BasicString[flights];
	//}
	//cin >> queries;
	//BasicString from, to;
	//cin >> from >> to >> type;
	
	/*City* kk= world.find("GDANSK");
	cout << kk->getName() << ": " << endl;
	kk->getNeighboursList().drawList();

	kk = world.find("SZCZECIN");
	cout << kk->getName() << ": " << endl;
	kk->getNeighboursList().drawList();

	kk = world.find("WARSZAWA");
	cout << kk->getName() << ": " << endl;
	kk->getNeighboursList().drawList();

	kk = world.find("WROCLAW");
	cout << kk->getName() << ": " << endl;
	kk->getNeighboursList().drawList();

	kk = world.find("KIELCE");
	cout << kk->getName() << ": " << endl;
	kk->getNeighboursList().drawList();

	kk = world.find("OPOLE");
	cout << kk->getName() << ": " << endl;
	kk->getNeighboursList().drawList();

	kk = world.find("KRAKOW");
	cout << kk->getName() << ": " << endl;
	kk->getNeighboursList().drawList();*/



	return 0;
}