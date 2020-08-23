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

std::vector<int>* Ai::randomHit(std::vector<std::vector<int>>* playerMap, unsigned int& widthMax, unsigned int& heightMax) {
	int positionX, positionY;
	bool isUsedX, isUsedY;

	if(difficultyLevel != "EASY" && changeHits)
		upgradeHits(playerMap, widthMax, heightMax);

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

void Ai::upgradeHits(std::vector<std::vector<int>>* playerMap, unsigned int& widthMax, unsigned int& heightMax) {
	int area;
	int freeAreaCount;
	const int allShipsArea = 15;

	area = widthMax * heightMax;
	freeAreaCount = area - allShipsArea;

	for(int i = 0; i < heightMax; i++) {
		for(int j = 0; j < widthMax; j++) {
			if((*playerMap)[j][i] == 0) { // free area
				freeAreaX.push_back(j);
				freeAreaY.push_back(i);	
			}
		}
	}

	if(area < 50) {
		if(difficultyLevel == "MEDIUM") {
			randomKnownFreeArea(10);
		}
		else { //hard	
			randomKnownFreeArea(15);
		}
	}
	else if(area >= 50 && area < 75) {
		if(difficultyLevel == "MEDIUM") {
			randomKnownFreeArea(20);
		}
		else {
			randomKnownFreeArea(25);
		}
	}
	else if(area >= 75 && area < 100) {
		if(difficultyLevel == "MEDIUM") {
                        randomKnownFreeArea(30);
                }
                else {
                        randomKnownFreeArea(35);
                }
	}
	else if(area >= 100 && area < 125) {
		if(difficultyLevel == "MEDIUM") {
                        randomKnownFreeArea(40);
                }
                else {
                        randomKnownFreeArea(45);
                }
	}
	else if(area >= 125 && area < 150) {
		if(difficultyLevel == "MEDIUM") {
                        randomKnownFreeArea(50);
                }
                else {
                        randomKnownFreeArea(55);
                }
	}
	else if(area >= 150 && area < 175) {
		if(difficultyLevel == "MEDIUM") {
			randomKnownFreeArea(60);
		}
		else {
			randomKnownFreeArea(65);
		}
	}
	else if(area >= 175 && area < 200) {
		if(difficultyLevel == "MEDIUM") {
                        randomKnownFreeArea(70);
                }
                else {
                        randomKnownFreeArea(75);
                }
	}
	else if(area >= 200 && area <= 225) {
		if(difficultyLevel == "MEDIUM") {
			randomKnownFreeArea(80);
		}
		else {
			randomKnownFreeArea(85);
		}
	}
		
	changeHits = false;
}

void Ai::randomKnownFreeArea(int knownArea) {
	int positionX, positionY;
	bool isUsedX, isUsedY;
	
	for(int i = 0; i < knownArea; i++) {
	        do {
	                isUsedX = false;
	                isUsedY = false;
 
	                std::random_device rd;
	                std::mt19937 gen(rd());

	                std::uniform_int_distribution<> dis(0, freeAreaX.size() - 1);

			auto draw = dis(gen);

	                positionX = freeAreaX[draw];
	                positionY = freeAreaY[draw];

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
 
	         usedHitX.push_back(positionX);
	         usedHitY.push_back(positionY);
	}
}
