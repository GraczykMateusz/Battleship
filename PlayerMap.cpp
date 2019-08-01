#include "PlayerMap.h"

#include <iostream>

PlayerMap::PlayerMap() {
	setVecMap2D();
}

void PlayerMap::showMapName() {
	std::cout << "Player's map:" << std::endl;
}

void PlayerMap::setShipsOnMap(std::vector<int>* ship) {
	vecMap2D[0][0] = (*ship)[0];
}
