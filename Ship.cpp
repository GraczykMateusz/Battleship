#include "Ship.h"

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

Ship::Ship() {
	shipPositionX = 0;
	shipPositionY = 0;
}

void Ship::showShipsSelection() {
	cout << "Ships:" << endl;
	cout << "1.\u25A0 2.\u25A0\u25A0 3.\u25A0\u25A0\u25A0 4.\u25A0\u25A0\u25A0\u25A0 5.\u25A0\u25A0\u25A0\u25A0\u25A0" << endl;
}

void Ship::setShipsPosition(unsigned int widthMax, unsigned int heightMax) {
	shipIsMoved = false; //First think that player doesnt move ship

	//help
	cout << "'-1' -left/top, '1' -right/bottom, '0' -accept position (do this twice)" << endl;
	
	//horizontal move (X)
	do { //protection against wrong input (go outside the map)
		cout << "Horizontal:";
		cin >> moveX;
	} while(shipPositionX + moveX < 0 || shipPositionX + moveX >= widthMax || moveX > 1 || moveX < -1);

	// set old and new position
	oldShipPositionX = shipPositionX;
	shipPositionX += moveX;
	shipIsMoved = true;

	//vertical move (Y)
	do { //protection against wrong input (go outside the map)
	cout << "Vertical:";
	cin >> moveY;
	} while(shipPositionY + moveY < 0 || shipPositionY + moveY >= heightMax ||  moveY > 1 || moveY < -1);

	// set old and new position
	oldShipPositionY = shipPositionY;
	shipPositionY += moveY;
	shipIsMoved = true;
}
