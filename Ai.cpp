#include "Ai.h"

#include <random>
#include <algorithm>

std::string Ai::difficultyLevel = "MEDIUM";
std::string* Ai::getDifficultyLevel() { return &difficultyLevel; }

void Ai::setPosition(std::vector<int>* ship, unsigned int& widthMax, unsigned int& heightMax, std::vector<std::vector<int>>* vecMap2D) {
	bool isSet = false;

	std::random_device rd;
	std::mt19937 gen(rd());
	
	std::uniform_int_distribution<> disX(0, widthMax);
	std::uniform_int_distribution<> disY(0, heightMax);
	std::bernoulli_distribution randBool(0.5);
	do {
		short counter = 0;
		bool isRotate = randBool(gen);		

		int positionX = disX(gen);
	        int positionY = disY(gen);

		if(positionX + (*ship).size() < widthMax && isRotate)
			if(positionY < heightMax)
				for(int i = 0; i < (*ship).size(); i++) {
					if((*vecMap2D)[positionX + i][positionY] == 0) {
						counter++;
						if(counter == (*ship).size()) {
							isRotateVec.push_back(isRotate);
							botShipPosition.push_back(positionX);
							botShipPosition.push_back(positionY);
							isSet = true;
						}
					}
				}	
		if(positionX < widthMax)
			if(positionY + (*ship).size() < heightMax && !isRotate)
				for(int j = 0; j < (*ship).size(); j++) {
					if((*vecMap2D)[positionX][positionY + j] == 0) {
						counter++;
						if(counter == (*ship).size()) {
							isRotateVec.push_back(isRotate);
							botShipPosition.push_back(positionX);
							botShipPosition.push_back(positionY);
							isSet = true;
						}
				}
			}			
	} while(!isSet);
}
#include <iostream>
std::vector<int>* Ai::randomHit(unsigned int widthMax, unsigned int heightMax) {
	int positionX, positionY;
	bool isUsedX, isUsedY;

	do {
		isUsedX = false;
		isUsedY = false;

		std::random_device rd;
	        std::mt19937 gen(rd());

	        std::uniform_int_distribution<> disX(0, widthMax - 1);
	        std::uniform_int_distribution<> disY(0, heightMax - 1);

		positionX = disX(gen);
	        positionY = disY(gen);	
		
		if(!usedHitX.empty() && !usedHitY.empty()) {
			for(int i = 0; i < usedHitX.size(); i++) {

				isUsedX = false;
				isUsedY = false;

				if(usedHitX[i] == positionX && usedHitY[i] == positionY) {

					isUsedX = true;
					isUsedY = true;
					break;
				}
			}
		}
	} while(isUsedX && isUsedY);

	randHit.push_back(positionX);
	randHit.push_back(positionY);

	usedHitX.push_back(positionX);
	usedHitY.push_back(positionY);

	return &randHit;
}
