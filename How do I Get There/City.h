#pragma once

#include "BasicString.h"
#include "List.h"
#include "Hashmap.h"

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

	int getPosX() const;
	int getPosY() const;
	int getId() const;
	BasicString getName() const;
	List<City>& getNeighboursList();
	void addFlight(Hashmap& world, const BasicString& to, int time);
	friend std::ostream& operator<<(std::ostream& os, const City& city);


	~City();
};

