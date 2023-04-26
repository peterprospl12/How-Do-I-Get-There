
#include "City.h"
#include "List.cpp"

City::City() {
	this->name = BasicString();
	this->posX = -15;
	this->posY = -15;
	this->neighbours = List<City>();
	this->id = -15;
}

City::City(BasicString name, int posX, int posY, int id) {
	this->name = name;
	this->posX = posX;
	this->posY = posY;
	this->neighbours = List<City>();
	this->id = id;
}

int City::getPosX() {
	return this->posX;
}

int City::getPosY() {
	return this->posY;
}

BasicString City::getName() {
	return this->name;
}

int City::getId() {
	return this->id;
}

Node<City>* City::getNeighbours() {
	return this->neighbours.getHead();
}

void City::setPosX(int posX) {
	this->posX = posX;
}

void City::setPosY(int posY) {
	this->posY = posY;
}

void City::setName(BasicString name) {
	this->name = name;
}

List<City>& City::getNeighboursList() {
	return this->neighbours;
}

std::ostream& operator<<(std::ostream& os, const City& city) {
	os << city.name << " (" << city.posX << ", " << city.posY << ")";
	return os;
}


City::~City() {
	

}