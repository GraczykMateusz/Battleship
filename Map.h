#pragma once
#include <vector>

class Map {
public:
	Map();
	~Map() = default;

	static unsigned int* getMapSizeHeight();
	static unsigned int* getMapSizeWidth();
	void setVecMap2D();
	void showMap();
protected:
	static unsigned int mapSizeHeight;
	static unsigned int mapSizeWidth;
	std::vector<std::vector<int>> vecMap2D; //[Width][Height]
	void setMap();	
	char setLastLetterAscii();
};
