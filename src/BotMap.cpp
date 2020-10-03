#include "BotMap.h"

#include <iostream>

using std::cout;
using std::endl;

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

void BotMap::showMap() {
        /*---------- Show (top) from A to J/T -------------*/
        if(mapSizeHeight < 10) //If height >10 we have more start-spaces before letters to correct proportions
                cout << ' ';
        else //If height <10 we have less start-spaces before letters to correct proportions
                cout << ' ' << ' ';
        for(char c ='A'; c <= setLastLetterAscii(); ++c) { // Show A - J/T
                cout << ' ' << c;
        }
        cout << endl; //Next line after show A - J/T

        /*--------------SHOW WHOLE MAP--------------*/
        for(int i = 0; i < mapSizeHeight; i++) { //Vertical
                for(int j = 0; j < mapSizeWidth; j++) { //Horizontal
                        if(j == 0) { //Set vertical numbers on the map's left                   
                                if(mapSizeHeight >= 10 && i + 1 < 10)
                                        cout << i + 1 << '.' << '|';
                                else
                                        cout << i + 1 << '|';
                        }
                        /*Position*/
                        if(vecMap2D[j][i] == 0) //Free 
                                cout << ' ';
                        if(vecMap2D[j][i] == 1) //Miss
                                cout << 'o';
                        if(vecMap2D[j][i] == 2) //Ship
                                cout << " ";
                        if(vecMap2D[j][i] == 3) //Hit
                                cout << 'X';
                        if(vecMap2D[j][i] == 4) //Ship on ship
                                cout << ' ';

                        cout << '|'; //Show vertical line which separates positions
                }
                cout << endl; //Next line

                for(int z = 0; z < 2*mapSizeWidth + 3; z++) //Show horizontal line which separates positions
                        cout << '-';
                cout << endl;
        }
        cout << endl;
}
