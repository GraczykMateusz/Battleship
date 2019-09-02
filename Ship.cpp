#include "Ship.h"

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

Ship::Ship() {
	oldShipPositionX = 0;
	oldShipPositionY = 0;
	shipPositionX = 0;
	shipPositionY = 0;
}

void Ship::showShipsSelection() {
	cout << "Ships:" << endl;
	cout << "1.\u25A0 2.\u25A0\u25A0 3.\u25A0\u25A0\u25A0 4.\u25A0\u25A0\u25A0\u25A0 5.\u25A0\u25A0\u25A0\u25A0\u25A0" << endl;
}

void Ship::setShipsPosition(std::vector<int>* ship, unsigned int widthMax, unsigned int heightMax, std::vector<std::vector<int>>* vecMap2D) {
	shipIsMoved = false; // First think that player doesnt move ship

	// help
	cout << "'-1' -left/top, '1' -right/bottom, '2' -rotate, '0' -accept position (do this twice)" << endl;
	
	// protection against set ship on the ship
	do {	
		// horizontal move (X)
		if(shipIsRotated) {
			do { // protection against wrong input (go outside the map) [shipIsntRotated]
				cout << "Horizontal:";
				cin >> moveX;
			} while(shipPositionX + moveX < 0 || shipPositionX + moveX >= widthMax || moveX > 1 || moveX < -1);
	
			// set old and new position
			if(moveX != 0) {
				oldShipPositionX = shipPositionX;
				shipPositionX += moveX;
				shipIsMoved = true;
			}
			else {
				oldShipPositionX = shipPositionX;
			}
		}
		else { // horizontal move (X) ROTATED SHIP
			do { // protection against wrong input (go outside the map) [shipIsRotated]
                                cout << "Horizontal:";
                                cin >> moveX;
                        } while(shipPositionX + moveX < 0 || shipPositionX + (*ship).size() + moveX >= widthMax || moveX > 1 || moveX < -1);
			
                       // set old and new position
                        if(moveX != 0) {
                                oldShipPositionX = shipPositionX;
                                shipPositionX += moveX;
                                shipIsMoved = true;
                        }
                        else {
                                oldShipPositionX = shipPositionX;
                        }
		}	
		// vertical move (Y)
		if(shipIsRotated) {
			do { // protection against wrong input (go outside the map) [shipIsntRotated]
				cout << "Vertical:";
				cin >> moveY;								
			} while(shipPositionY + moveY < 0 || shipPositionY + moveY >= heightMax || shipPositionY + (*ship).size() + moveY > heightMax || moveY > 1 || moveY < -1);
	
			// set old and new position
			if(moveY != 0) {
				oldShipPositionY = shipPositionY;
				shipPositionY += moveY;
				shipIsMoved = true;
			}
			else {
				oldShipPositionY = shipPositionY;
			}
		}
		else { // vertical move (Y) ROTATED SHIP
			do { // protection against wrong input (go outside the map)                     
                                cout << "Vertical:";                                                    
                                cin >> moveY;                                                           
                        } while(shipPositionY + moveY < 0 || shipPositionY + moveY >= heightMax || moveY > 1 || moveY < -1);
			
			// set old and new position
                        if(moveY != 0) {
                                oldShipPositionY = shipPositionY;
                                shipPositionY += moveY;
                                shipIsMoved = true;
                        }
                        else {
                                oldShipPositionY = shipPositionY;
                        }
		}
	} while(checkIfShipIsOnShip(widthMax, heightMax, vecMap2D) && moveX == 0 && moveY == 0);
}

bool Ship::checkIfShipIsOnShip(unsigned int widthMax, unsigned int heightMax, std::vector<std::vector<int>>* vecMap2D) {
	for(int i = 0; i < widthMax; i++) {
		for(int j = 0; j < heightMax; j++) {
			if((*vecMap2D)[i][j] == 4)
				return true;
		}
	}
	return false;
}

void Ship::resetPosition() {
	oldShipPositionX = 0;
	oldShipPositionY = 0;
	shipPositionX = 0;
	shipPositionY = 0;
}
