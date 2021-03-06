#ifndef BOT_MAP_H
#define BOT_MAP_H

#include "Map.h"
#include <vector>

class BotMap : public Map {
public:
	BotMap();
	~BotMap() = default;
	
	void showMap();
	void showMapName();
	void setShip(std::vector<int>* botShipPosition, std::vector<int>* isRotateVec, std::vector<int>* ship);
private:
};

#endif
