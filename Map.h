#pragma once
#include <vector>

class Map {
public:
	Map();
	~Map() = default;

	static unsigned int* getMapSizeHeight();
	static unsigned int* getMapSizeWidth();
	std::vector<std::vector<int>>* getVecMap2D() { return &vecMap2D; }
	void setVecMap2D();
	void showMap();
private:
	static unsigned int mapSizeHeight;
	static unsigned int mapSizeWidth;
	std::vector<std::vector<int>> vecMap2D; //[Width][Height]
	void setMap();	
	char setLastLetterAscii();
};
