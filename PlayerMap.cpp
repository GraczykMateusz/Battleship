#include "PlayerMap.h"

#include <iostream>

PlayerMap::PlayerMap() {
	setVecMap2D();
}

void PlayerMap::showMapName() {
	std::cout << "Player's map:" << std::endl;
}

void PlayerMap::setShipsOnMap(std::vector<int>* ship, int* shipPositionX, int* shipPositionY) {
	vecMap2D[*shipPositionX][*shipPositionY] = (*ship)[0];
}

void PlayerMap::resetOldShipPosition(int oldShipPositionX, int oldShipPositionY) {
	vecMap2D[oldShipPositionX][oldShipPositionY] = 0; // '0' means free position
}
