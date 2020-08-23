#include <string>
#include <vector>

class Ai {
public:
	Ai() = default;
	~Ai() = default;

	static std::string* getDifficultyLevel();
	void setPosition(std::vector<int>* ship, unsigned int& widthMax, unsigned int& heightMax, std::vector<std::vector<int>>* vecMap2D);

	std::vector<int>* randomHit(std::vector<std::vector<int>>* playerMap, unsigned int& widthMax, unsigned int& heightMax);
	std::vector<int>* getIsRotateVec() { return &isRotateVec; }
	std::vector<int>* getBotShipPosition() { return &botShipPosition; }

private:
	static std::string difficultyLevel;
	void upgradeHits(std::vector<std::vector<int>>* playerMap, unsigned int& widthMax, unsigned int& heightMax);
	bool changeHits = true;

	void randomKnownFreeArea(int knownArea);

	std::vector<int> isRotateVec;
	std::vector<int> botShipPosition; 
	std::vector<int> randHit;

	std::vector<int> freeAreaX;
	std::vector<int> freeAreaY;

	std::vector<int> usedHitX;
	std::vector<int> usedHitY;
};
