#include <vector>

#include "Map.h"

class PlayerMap	 : public Map {
public:
	PlayerMap();
	~PlayerMap() = default;
	
	void showMapName();
	void setShipsOnMap(std::vector<int>* ship);
};
