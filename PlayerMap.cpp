#include "PlayerMap.h"

#include <iostream>

PlayerMap::PlayerMap() {
	setVecMap2D();
}

void PlayerMap::showMapName() {
	std::cout << "Player's map:" << std::endl;
}

//---------Reset position--------//
void PlayerMap::resetOldShip1Position(int oldShipPositionX, int oldShipPositionY) {
        vecMap2D[oldShipPositionX][oldShipPositionY] = 0; // '0' means free position
}

void PlayerMap::resetOldShip2Position(int oldShipPositionX, int oldShipPositionY) {
        vecMap2D[oldShipPositionX][oldShipPositionY] = 0; 
	vecMap2D[oldShipPositionX][oldShipPositionY + 1] = 0;
}

void PlayerMap::resetOldShip3Position(int oldShipPositionX, int oldShipPositionY) {
        vecMap2D[oldShipPositionX][oldShipPositionY] = 0;
	vecMap2D[oldShipPositionX][oldShipPositionY + 1] = 0; 
	vecMap2D[oldShipPositionX][oldShipPositionY + 2] = 0;
}

void PlayerMap::resetOldShip4Position(int oldShipPositionX, int oldShipPositionY) {
        vecMap2D[oldShipPositionX][oldShipPositionY] = 0; 
	vecMap2D[oldShipPositionX][oldShipPositionY + 1] = 0;
	vecMap2D[oldShipPositionX][oldShipPositionY + 2] = 0;
	vecMap2D[oldShipPositionX][oldShipPositionY + 3] = 0;
}

void PlayerMap::resetOldShip5Position(int oldShipPositionX, int oldShipPositionY) {
        vecMap2D[oldShipPositionX][oldShipPositionY] = 0; 
	vecMap2D[oldShipPositionX][oldShipPositionY + 1] = 0;
	vecMap2D[oldShipPositionX][oldShipPositionY + 2] = 0;
	vecMap2D[oldShipPositionX][oldShipPositionY + 3] = 0;
	vecMap2D[oldShipPositionX][oldShipPositionY + 4] = 0;
}

//---------Set ship into the map---------//
void PlayerMap::setShip1(std::vector<int>* ship, int* shipPositionX, int* shipPositionY) {
	vecMap2D[*shipPositionX][*shipPositionY + 0] = (*ship)[0];
}

void PlayerMap::setShip2(std::vector<int>* ship, int* shipPositionX, int* shipPositionY) {
	vecMap2D[*shipPositionX][*shipPositionY + 0] = (*ship)[0];
	vecMap2D[*shipPositionX][*shipPositionY + 1] = (*ship)[1];
}

void PlayerMap::setShip3(std::vector<int>* ship, int* shipPositionX, int* shipPositionY) {
	vecMap2D[*shipPositionX][*shipPositionY + 0] = (*ship)[0];
        vecMap2D[*shipPositionX][*shipPositionY + 1] = (*ship)[1];
	vecMap2D[*shipPositionX][*shipPositionY + 2] = (*ship)[2];
}

void PlayerMap::setShip4(std::vector<int>* ship, int* shipPositionX, int* shipPositionY) {
	vecMap2D[*shipPositionX][*shipPositionY + 0] = (*ship)[0];
	vecMap2D[*shipPositionX][*shipPositionY + 1] = (*ship)[1];
	vecMap2D[*shipPositionX][*shipPositionY + 2] = (*ship)[2];
	vecMap2D[*shipPositionX][*shipPositionY + 3] = (*ship)[3];
}

void PlayerMap::setShip5(std::vector<int>* ship, int* shipPositionX, int* shipPositionY) {
	vecMap2D[*shipPositionX][*shipPositionY + 0] = (*ship)[0];
	vecMap2D[*shipPositionX][*shipPositionY + 1] = (*ship)[1];
	vecMap2D[*shipPositionX][*shipPositionY + 2] = (*ship)[2];
	vecMap2D[*shipPositionX][*shipPositionY + 3] = (*ship)[3];
	vecMap2D[*shipPositionX][*shipPositionY + 4] = (*ship)[4];
}

