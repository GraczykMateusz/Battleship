#include <vector>

class Ship {
public:
	Ship() = default;
	~Ship() = default;

	void showShipsSelection();

	std::vector<int>* getShip1() { return &ship1; }
	std::vector<int>* getShip2() { return &ship2; }
	std::vector<int>* getShip3() { return &ship3; }
	std::vector<int>* getShip4() { return &ship4; }
	std::vector<int>* getShip5() { return &ship5; }
private:                        
	std::vector<int> ship1 {1, 2}; // '2' is a number which means ship
	std::vector<int> ship2 {2, 2};
	std::vector<int> ship3 {3, 2};
	std::vector<int> ship4 {4, 2}; 
	std::vector<int> ship5 {5, 2}; 
};
