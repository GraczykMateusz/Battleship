#include "PlayerMap.h"

#include <iostream>

PlayerMap::PlayerMap() {
	setVecMap2D();
}

void PlayerMap::showMapName() {
	std::cout << "Player's map:" << std::endl;
}

void PlayerMap::resetOldShipPosition(std::vector<int>* ship, int oldShipPositionX, int oldShipPositionY) {
	for(int i = 0; i <= (*ship).size(); i++)
	        vecMap2D[oldShipPositionX][oldShipPositionY + i] = 0; // '0' means free position
}

void PlayerMap::setShip(std::vector<int>* ship, int* shipPositionX, int* shipPositionY) {
	for(int i = 0; i <= (*ship).size(); i++)
		vecMap2D[*shipPositionX][*shipPositionY + i] = (*ship)[i];
}
