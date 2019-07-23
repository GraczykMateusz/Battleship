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
	enum HorizontalLetters {
		A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, R, S, T, U // 0-19
	};
	//Map
	unsigned int mapSizeHeight;
	unsigned int mapSizeWidth;
	std::vector<std::vector<int>> vecMap2D;
	void setMap();	
};


