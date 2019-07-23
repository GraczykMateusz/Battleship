#include <iostream>
#include "Map.h"
#include <vector>

Map::Map() {
	mapSizeHeight = 10;
	mapSizeWidth = 15;	
	setVecMap2D();
}

void Map::setVecMap2D() {
	vecMap2D.resize(mapSizeWidth);
	for(unsigned int i = 0; i < mapSizeWidth; i++) {
		vecMap2D[i].resize(mapSizeHeight);
	}
}

void Map::showMap() {
	
}
