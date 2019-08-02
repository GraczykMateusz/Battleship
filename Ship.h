#include <vector>

class Ship {
public:
	Ship();
	~Ship() = default;

	void showShipsSelection();
	void setShipsPosition();

	int* getShipPositionX() { return &shipPositionX; }
	int* getShipPositionY() { return &shipPositionY; }
	int getOldShipPositionX() { return oldShipPositionX; }
	int getOldShipPositionY() { return oldShipPositionY; }
	short getMoveX() { return moveX; }
	short getMoveY() { return moveY; }
	bool getShipIsMoved() { return shipIsMoved; }	

	std::vector<int>* getShip1() { return &ship1; }
	std::vector<int>* getShip2() { return &ship2; }
	std::vector<int>* getShip3() { return &ship3; }
	std::vector<int>* getShip4() { return &ship4; }
	std::vector<int>* getShip5() { return &ship5; }
private:                        
	int shipPositionX;
        int shipPositionY;
	int oldShipPositionX;
	int oldShipPositionY;
	short moveX;
	short moveY;
	bool shipIsMoved;

	std::vector<int> ship1{std::vector<int>(1, 2)}; // '2' is a number which means ship
	std::vector<int> ship2{std::vector<int>(2, 2)};
	std::vector<int> ship3{std::vector<int>(3, 2)};
	std::vector<int> ship4{std::vector<int>(4, 2)}; 
	std::vector<int> ship5{std::vector<int>(5, 2)}; 
};
