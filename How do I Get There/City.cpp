
#include "City.h"
#include "List.cpp"
#include "Hashmap.h"
City::City() 
	: name(""), posX(-1), posY(-1), id(-1)
{
	this->neighbours = List<City>();
}

City::City(BasicString name, int posX, int posY, int id)
	: name(name), posX(posX), posY(posY), id(id) 
{
	this->neighbours = List<City>();
}


int City::getPosX() const {
	return this->posX;
}

int City::getPosY() const {
	return this->posY;
}

BasicString City::getName() const {
	return this->name;
}

int City::getId() const {
	return this->id;
}


List<City>& City::getNeighboursList() {
	return this->neighbours;
}

void City::addFlight(Hashmap& world, const BasicString& to, int time) {
	neighbours.insert(world.find(to.str), time);
}


std::ostream& operator<<(std::ostream& os, const City& city) {
	os << city.name << " (" << city.posX << ", " << city.posY << ")";
	return os;
}


City::~City() {

}