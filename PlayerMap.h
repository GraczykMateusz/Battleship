#include <vector>

#include "Map.h"

class PlayerMap	 : public Map {
public:
	PlayerMap();
	~PlayerMap() = default;
	
	void showMapName();

	//reset old ship position
	void resetOldShip1Position(int oldShipPositionX, int oldShipPositionY);
	void resetOldShip2Position(int oldShipPositionX, int oldShipPositionY);
	void resetOldShip3Position(int oldShipPositionX, int oldShipPositionY);
	void resetOldShip4Position(int oldShipPositionX, int oldShipPositionY);
	void resetOldShip5Position(int oldShipPositionX, int oldShipPositionY);

	//Set ship into the map
	void setShip1(std::vector<int>* ship, int* shipPositionX, int* shipPositionY);
	void setShip2(std::vector<int>* ship, int* shipPositionX, int* shipPositionY);
	void setShip3(std::vector<int>* ship, int* shipPositionX, int* shipPositionY);
	void setShip4(std::vector<int>* ship, int* shipPositionX, int* shipPositionY);
	void setShip5(std::vector<int>* ship, int* shipPositionX, int* shipPositionY);

};
