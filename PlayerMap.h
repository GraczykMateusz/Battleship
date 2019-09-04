#include <vector>

#include "Map.h"

class PlayerMap	 : public Map {
public:
	PlayerMap();
	~PlayerMap() = default;
	
	void showMapName();

	void resetOldShipPosition(std::vector<int>* ship, bool shipIsRotated, int oldShipPositionX, int oldShipPositionY, short moveX, int* shipPositionX, int* shipPositionY);

	void setShip(std::vector<int>* ship, bool shipIsRotated, int* shipPositionX, int* shipPositionY);
	bool isShipOnMap(short shipNumber);
	void shipIsOnMap(short shipNumber);
	std::vector<short> getVecShipOnMap() { return vecShipOnMap; }
private:
	std::vector<short> vecShipOnMap;
};
