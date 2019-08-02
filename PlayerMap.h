#include <vector>

#include "Map.h"

class PlayerMap	 : public Map {
public:
	PlayerMap();
	~PlayerMap() = default;
	
	void showMapName();
	void setShipsOnMap(std::vector<int>* ship, int* shipPositionX, int* shipPositionY);
	void resetOldShipPosition(int oldShipPositionX, int oldShipPositionY);
};
