#include "Ai.h"

#include <cstdlib>
#include <time.h>
#include <random>

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
