#include <string>
#include <vector>

class Ai {
public:
	Ai() = default;
	~Ai() = default;

	static std::string* getDifficultyLevel();
	void setPosition(std::vector<int>* ship, unsigned int& widthMax, unsigned int& heightMax, std::vector<std::vector<int>>* vecMap2D);
	std::vector<int>* getIsRotateVec() { return &isRotateVec; }
	std::vector<int>* getBotShipPosition() { return &botShipPosition; }
private:
	static std::string difficultyLevel;
	std::vector<int> isRotateVec;
	std::vector<int> botShipPosition; 
};
