#include <vector>

class Map {
public:
	Map();
	~Map() = default;

	unsigned int* getMapSizeHeight() { return &mapSizeHeight; }
	unsigned int* getMapSizeWidth() { return &mapSizeWidth; }
	std::vector<std::vector<int>>* getVecMap2D() { return &vecMap2D; }
	void setVecMap2D();
	void showMap();
private:
	unsigned int mapSizeHeight;
	unsigned int mapSizeWidth;
	std::vector<std::vector<int>> vecMap2D; //[Width][Height]
	void setMap();	
	char setLastLetterAscii();
};


