#include <vector>

class Ship {
public:
	Ship();
	~Ship() = default;

	// Menu
	void showShipsSelection();

	// New position
	int* getShipPositionX() { return &shipPositionX; }
	int* getShipPositionY() { return &shipPositionY; }
	void setShipsPosition(std::vector<int>* ship, unsigned int widthMax, unsigned int heightMax, std::vector<std::vector<int>>* vecMap2D);
	void resetPosition();	

	// Old position
	int getOldShipPositionX() { return oldShipPositionX; }
	int getOldShipPositionY() { return oldShipPositionY; }

	// Move
	short getMoveX() { return moveX; }
	short getMoveY() { return moveY; }

	// Move settings
	bool getShipIsMoved() { return shipIsMoved; }	
	bool getShipIsRotated() { return shipIsRotated; }
	
	// Ships count
	short getShipMaxCount() { return shipMaxCount; }
	
	// Ships
	std::vector<int>* getShip1() { return &ship1; }
	std::vector<int>* getShip2() { return &ship2; }
	std::vector<int>* getShip3() { return &ship3; }
	std::vector<int>* getShip4() { return &ship4; }
	std::vector<int>* getShip5() { return &ship5; }
private:
	// New position                        
	int shipPositionX;
        int shipPositionY;

	// Old position
	int oldShipPositionX;
	int oldShipPositionY;

	// Move
	short moveX;
	short moveY;

	// Move settings
	bool shipIsMoved;
	bool shipIsRotated;
	bool checkIfShipIsOnShip(unsigned int widthMax, unsigned int heightMax, std::vector<std::vector<int>>* vecMap2D);	

	// Ships count
	const short shipMaxCount = 5;

	// Ships
	std::vector<int> ship1{std::vector<int>(1, 2)}; // '2' is a number which means ship
	std::vector<int> ship2{std::vector<int>(2, 2)};
	std::vector<int> ship3{std::vector<int>(3, 2)};
	std::vector<int> ship4{std::vector<int>(4, 2)}; 
	std::vector<int> ship5{std::vector<int>(5, 2)}; 
};
