#include "Algorithms.h"

using std::cout;
using std::endl;

void djikstra_algorithm(Hashmap world, BasicString start, BasicString end, bool showPath) {

	if (start.str == end.str) {
		cout << "0" << endl;
		return;
	}

	City* from = world.find(start.str);
	City* to = world.find(end.str);

	int size = world.getCurrSize();

	bool* visited = new bool[size];
	City** previous = new City * [size];
	int* distance = new int[size];
	BasicString* path = new BasicString[size];

	MinHeap minHeap;

	for (int i = 0; i < size; i++) {
		visited[i] = false;
		distance[i] = INT_MAX;
		previous[i] = nullptr;
		path[i] = BasicString();
	}

	distance[from->getId()] = 0;
	minHeap.insert(from, (distance[from->getId()]));
	while (!minHeap.empty()) {
		City* current = minHeap.cities[0];
		minHeap.erase(0);

		if (current->getId() == to->getId()) {
			break;
		}


		if (visited[current->getId()]) {
			continue;
		}

		visited[current->getId()] = true;

		Node<City>* neighborNode = current->getNeighboursList().getHead();
		for (int i = 0; i < current->getNeighboursList().getSize(); i++) {

			City* neighbor = neighborNode->GetValue();

			int newDist = distance[current->getId()] + neighborNode->getDistance();

			if (newDist < distance[neighbor->getId()]) {

				distance[neighbor->getId()] = newDist;
				previous[neighbor->getId()] = current;

				minHeap.insert(neighbor, newDist);

			}
			neighborNode = neighborNode->GetNext();
		}
	}


	std::cout << distance[to->getId()];
	if (showPath) {
		Stack<BasicString> pathStack;
		BasicString currName = from->getName();
		City* currentCity = to;
		while (currentCity != nullptr) {
			pathStack.push(currentCity->getName());
			currentCity = previous[currentCity->getId()];
		}
		while (!pathStack.isEmpty()) {
			BasicString cityName = pathStack.top();
			pathStack.pop();
			if (cityName != start && cityName != end) {
				std::cout << " " << cityName;
			}
		}
	}

	std::cout << endl;
	delete[] visited;
	delete[] previous;
	delete[] distance;
	delete[] path;
}







bool checkForMove(char** map, int mapWidth, int mapHeight, int currX, int currY) {
	if (currY + 1 < mapHeight) {
		if ((map[currY + 1][currX] == '#' || map[currY + 1][currX] == '*')) {
			return false;

		}
	}
	if (currY - 1 >= 0) {
		if ((map[currY - 1][currX] == '#' || map[currY - 1][currX] == '*')) {
			return false;
		}
	}
	if (currX + 1 < mapWidth) {
		if ((map[currY][currX + 1] == '#' || map[currY][currX + 1] == '*')) {
			return false;
		}
	}
	if (currX - 1 >= 0) {
		if ((map[currY][currX - 1] == '#' || map[currY][currX - 1] == '*')) {
			return false;

		}
	}
	return true;
}

void checkForBranches(Queue<qNode>& q, char** map, int distance, int mapWidth, int mapHeight, int currX, int currY, bool** visited) {
	if (currY + 1 < mapHeight) {
		if ((map[currY + 1][currX] == '#' || map[currY + 1][currX] == '*') && visited[currY + 1][currX] == false) {
			q.insert(currX, currY + 1, distance);
			visited[currY + 1][currX] = true;

		}
	}
	if (currY - 1 >= 0) {
		if ((map[currY - 1][currX] == '#' || map[currY - 1][currX] == '*') && visited[currY - 1][currX] == false) {
			q.insert(currX, currY - 1, distance);
			visited[currY - 1][currX] = true;
		}
	}
	if (currX + 1 < mapWidth) {
		if ((map[currY][currX + 1] == '#' || map[currY][currX + 1] == '*') && visited[currY][currX + 1] == false) {
			q.insert(currX + 1, currY, distance);
			visited[currY][currX + 1] = true;
		}
	}
	if (currX - 1 >= 0) {
		if ((map[currY][currX - 1] == '#' || map[currY][currX - 1] == '*') && visited[currY][currX - 1] == false) {
			q.insert(currX - 1, currY, distance);
			visited[currY][currX - 1] = true;

		}
	}
}


void findNeighbours(char** map, Hashmap& world, BasicString** nameMap, int width, int height, City* city) {
	if (checkForMove(map, width, height, city->getPosX(), city->getPosY())) {
		return;
	}
	int distance = 0;
	int y = city->getPosY();
	int x = city->getPosX();
	bool** visited = new bool* [height];
	for (int i = 0; i < height; i++) {
		visited[i] = new bool[width];
		for (int j = 0; j < width; j++) {
			visited[i][j] = false;
		}
	}
	Queue<qNode> q;
	visited[y][x] = true;
	checkForBranches(q, map, distance, width, height, x, y, visited);
	while (!q.empty()) {
		qNode* temp = q.getHead();
		x = temp->posX;
		y = temp->posY;
		distance = temp->distance;
		q.pop();
		distance++;
		visited[y][x] = true;
		if (map[y][x] == '*') {

			BasicString name = nameMap[y][x];
			city->getNeighboursList().insert(world.find(name.str), distance);

			visited[y][x] = true;
			continue;
		}

		checkForBranches(q, map, distance, width, height, x, y, visited);

	}
	for (int i = 0; i < height; i++) {
		delete[] visited[i];
	}
	delete[] visited;
}



void processMap(Queue<qCity>& cities, BasicString** nameMap, char** map, int mapWidth, int mapHeight, Hashmap& world) {
	int currCityX, currCityY;
	char c;

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			c = getchar();
			if (c == '\n') {
				j--;
				continue;
			}

			map[i][j] = c;
		}
	}

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
				while (currX < mapWidth && map[currY][currX] != '#' && map[currY][currX] != '.' && map[currY][currX] != '*') {
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
}


void readFlights(Hashmap& world) {
	int flights = 0, time = 0;
	char from[20], to[20];
	int counter = 0;
	getchar();
	int testChar = getchar();
	char testChar2;
	while (testChar != EOF && testChar != '\n') {
		flights = flights * 10 + testChar - '0';
		testChar = getchar();
	}
	for (int i = 0; i < flights; i++) {



		while ((testChar2 = getchar()) != '\n' && testChar2 != EOF && testChar2 != ' ') {
			from[counter++] = testChar2;
		}
		from[counter] = '\0';
		counter = 0;




		while ((testChar2 = getchar()) != '\n' && testChar2 != EOF && testChar2 != ' ') {
			to[counter++] = testChar2;
		}
		to[counter] = '\0';
		counter = 0;



		testChar = getchar();
		while (testChar != EOF && testChar != '\n') {
			time = time * 10 + testChar - '0';
			testChar = getchar();
		}
		world.find(from)->addFlight(world, to, time);
		time = 0;
	}

}


void readQueries(Hashmap& world) {
	int queries, type;
	char from[20], to[20];
	std::cin >> queries;
	for (int i = 0; i < queries; i++) {
		std::cin >> from >> to >> type;
		djikstra_algorithm(world, from, to, type);
	}
}