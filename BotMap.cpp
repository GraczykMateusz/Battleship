#include "BotMap.h"

#include <iostream>

BotMap::BotMap() {
	setVecMap2D();
}

void BotMap::showMapName() {
        std::cout << "Bot's map:" << std::endl;
}

void BotMap::setShip(std::vector<int>* botShipPosition, std::vector<int>* isRotateVec) {
	//Ship5
	vecMap2D[(*botShipPosition)[0]][(*botShipPosition)[1]] += 2;
	
	//Ship4
	vecMap2D[(*botShipPosition)[2]][(*botShipPosition)[3]] += 2;

	//Ship3
	vecMap2D[(*botShipPosition)[4]][(*botShipPosition)[5]] += 2;

	//Ship2
	vecMap2D[(*botShipPosition)[6]][(*botShipPosition)[7]] += 2;

	//Ship1
	vecMap2D[(*botShipPosition)[8]][(*botShipPosition)[9]] += 2;
}
