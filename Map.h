//FILENAME: Map.h
#include <vector>

class Map {
public:
	Map(int mapSizeGM);
	~Map() = default;

	int getMapSize() { return mapSize; }
	std::vector<std::vector<int>> getVecMap2D() { return this->vecMap2D; }
private:
	unsigned int mapSize;
	std::vector<std::vector<int>> vecMap2D { mapSize, std::vector<int>(mapSize, 0) };
	void setMapSize(int mapSizeGM) { mapSize = mapSizeGM; }	
};
