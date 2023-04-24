#pragma once
#include "BasicString.h"
#include "List.h"


struct MainCity {
	BasicString name;
	int posX;
	int posY;
	List<MainCity> neighbours;
};

typedef MainCity City;