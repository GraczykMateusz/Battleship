#include <iostream>
#include <vector>

#include "Map.h"

using std::cout;
using std::endl;

Map::Map() {
	mapSizeHeight = 5;
	mapSizeWidth = 10;	
	setVecMap2D();
}

void Map::setVecMap2D() {
	vecMap2D.resize(mapSizeWidth);
	for(unsigned int i = 0; i < mapSizeWidth; i++) {
		vecMap2D[i].resize(mapSizeHeight);
	}
}

char Map::setLastLetterAscii() {
	return (char)(mapSizeWidth + 64); //Add 64 to convert from int to ascii; 'A' = 65, 'B' = 66 etc.
}

void Map::showMap() {
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
			if(vecMap2D[j][i] == -1) //Miss
				cout << 'o';		
			if(vecMap2D[j][i] == 0) //Free 
				cout << ' ';
			if(vecMap2D[j][i] == 1) //Hit
				cout << 'X';
			
			cout << '|'; //Show vertical line which separates positions
		}
		cout << endl; //Next line

		for(int z = 0; z < 2*mapSizeWidth + 3; z++) //Show horizontal line which separates positions
			cout << '-';
		cout << endl;	
	}	
	cout << endl;
}
