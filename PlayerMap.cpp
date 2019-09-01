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
		        vecMap2D[oldShipPositionX][oldShipPositionY + i] -= 2; // '0' means free position
	}
	else {
		for(int i = 0; i < (*ship).size(); i++)
                        vecMap2D[oldShipPositionX + i][oldShipPositionY] -= 2;
	}
}

void PlayerMap::setShip(std::vector<int>* ship, bool shipIsRotated, int* shipPositionX, int* shipPositionY) {
	if(!shipIsRotated) {
		for(int i = 0; i < (*ship).size(); i++)
			vecMap2D[*shipPositionX][*shipPositionY + i] += 2; // '2' means the ship
	}
	else {
		for(int i = 0; i < (*ship).size(); i++)
                        vecMap2D[*shipPositionX + i][*shipPositionY] += 2;
	}
}

void PlayerMap::shipIsOnMap(short shipNumber) {
	vecShipOnMap.push_back(shipNumber);
	std::sort(vecShipOnMap.begin(), vecShipOnMap.end());
}

bool PlayerMap::isShipOnMap(short shipNumber) {
	return std::binary_search(vecShipOnMap.begin(), vecShipOnMap.end(), shipNumber);
}
