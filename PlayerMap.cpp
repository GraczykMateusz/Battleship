#include "PlayerMap.h"

#include <algorithm>
#include <iostream>

PlayerMap::PlayerMap() {
	setVecMap2D();
}

void PlayerMap::showMapName() {
	std::cout << "Player's map:" << std::endl;
}

void PlayerMap::resetOldShipPosition(std::vector<int>* ship, bool shipIsRotated, int oldShipPositionX, int oldShipPositionY) {
	if(!shipIsRotated) {
		for(int i = 0; i < (*ship).size(); i++)
		        vecMap2D[oldShipPositionX][oldShipPositionY + i] = 0; // '0' means free position
	}
	else {
		for(int i = 0; i < (*ship).size(); i++)
                        vecMap2D[oldShipPositionX + i][oldShipPositionY] = 0;
	}
}

void PlayerMap::setShip(std::vector<int>* ship, bool shipIsRotated, int* shipPositionX, int* shipPositionY) {
	if(!shipIsRotated) {
		for(int i = 0; i < (*ship).size(); i++)
			vecMap2D[*shipPositionX][*shipPositionY + i] = (*ship)[i];
	}
	else {
		for(int i = 0; i < (*ship).size(); i++)
                        vecMap2D[*shipPositionX + i][*shipPositionY] = (*ship)[i];
	}
}

void PlayerMap::shipIsOnMap(short shipNumber) {
	std::cout << vecShipOnMap.size() << std::endl;
}

bool PlayerMap::isShipOnMap(short shipNumber) {
	return std::binary_search(vecShipOnMap.begin(), vecShipOnMap.end(), shipNumber);
}
