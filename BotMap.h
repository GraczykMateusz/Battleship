#include "Map.h"
#include <vector>

class BotMap : public Map {
public:
	BotMap();
	~BotMap() = default;

	void showMapName();
	void setShip(std::vector<int>* botShipPosition, std::vector<int>* isRotateVec, std::vector<int>* ship);
private:
};
