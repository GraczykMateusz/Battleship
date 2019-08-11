#include <vector>

#include "Map.h"

class PlayerMap	 : public Map {
public:
	PlayerMap();
	~PlayerMap() = default;
	
	void showMapName();

	void resetOldShipPosition(std::vector<int>* ship, bool shipIsRotated, int oldShipPositionX, int oldShipPositionY);

	void setShip(std::vector<int>* ship, bool shipIsRotated, int* shipPositionX, int* shipPositionY);
private:
};
