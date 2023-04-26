#pragma once

#include "BasicString.h"
#include "List.h"

class City {
private:
	BasicString name;
	int posX;
	int posY;
	List<City> neighbours;
	int id;
public:
	City();
	City(BasicString name, int posX, int posY, int id);

	int getPosX();
	int getPosY();
	int getId();
	BasicString getName();
	void setPosX(int posX);
	void setPosY(int posY);
	void setName(BasicString name);
	Node<City>* getNeighbours();
	List<City>& getNeighboursList();
	friend std::ostream& operator<<(std::ostream& os, const City& city);


	~City();
};

