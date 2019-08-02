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

void Ship::setShipsPosition() {
	shipIsMoved = false; //First think that player doesnt move ship

	//help
	cout << "'-1' -left/top, '1' -right/bottom, '0' -accept position" << endl;
	
	//horizontal move
	cout << "Horizontal:";
	cin >> moveX;
	oldShipPositionX = shipPositionX;
	if(moveX != 0) {
		shipPositionX += moveX;
		shipIsMoved = true;
	}
	//vertical move
	cout << "Vertical:";
	cin >> moveY;
	oldShipPositionY = shipPositionY;
	if(moveY != 0) {
		shipPositionY += moveY;
		shipIsMoved = true;
	}
}
