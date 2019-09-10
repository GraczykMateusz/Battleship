#include "BotMap.h"

#include <iostream>

BotMap::BotMap() {
	setVecMap2D();
}

void BotMap::showMapName() {
        std::cout << "Bot's map:" << std::endl;
}

void BotMap::setShip(std::vector<int>* botShipPosition, std::vector<int>* isRotateVec, std::vector<int>* ship) {
	vecMap2D[(*botShipPosition)[0]][(*botShipPosition)[1]] += 2;

	if((*isRotateVec)[0] == true) {
		for(int i = 1; i < (*ship).size(); i++)
			vecMap2D[(*botShipPosition)[0] + i][(*botShipPosition)[1]] += 2;
	}
	else {
		for(int i = 1; i < (*ship).size(); i++)
			vecMap2D[(*botShipPosition)[0]][(*botShipPosition)[1] + i] += 2;
	}
	(*botShipPosition).clear();
	(*isRotateVec).clear();
}
