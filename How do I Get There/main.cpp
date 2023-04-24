#include <iostream>
#include "BasicString.h"





int main()
{
	std::cout << hash("Gdañsk") << std::endl;
	std::cout << hash("Krakow") << std::endl;
	std::cout << hash("Kraków") << std::endl;
	std::cout << hash("Poznan") << std::endl;
	std::cout << hash("Zakopane") << std::endl;
	std::cout << hash("Warszawa") << std::endl;
	std::cout << hash("Bielskobiala") << std::endl;
	std::cout << hash("Ko³obrzeg") << std::endl;
	std::cout << hash("Armata") << std::endl;
	std::cout << hash("Londyn") << std::endl;
	std::cout << hash("Moskwa") << std::endl;









	/*char** map;
	int mapWidth, mapHeight;
	std::cin >> mapWidth >> mapHeight;


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
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}*/



	return 0;
}