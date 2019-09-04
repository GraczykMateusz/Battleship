#include <iostream>
#include <memory>
#include <string>

#include "GameManager.h"
#include "Map.h"
#include "Ai.h"
#include "systemClear.h"
#include "BotMap.h"
#include "PlayerMap.h"
#include "Ship.h"

using std::cin;
using std::cout;
using std::endl;

/*------------MENU-------------*/
char GameManager::menu() {
	systemClear();
	showMenu();
	return playerSelect();	
}

void GameManager::showMenu() {
	cout << "Welcome to BattleShip!" << endl;
	cout << "1.Start" << endl;
	cout << "2.Settings" << endl;
	cout << "3.Exit" << endl;
}

char GameManager::playerSelect() {
	cout << "Select:";
	cin >> select;
	return select;
}
/*----------MENU-END-------------*/

/*------------START--------------*/
bool GameManager::startGame() {
	std::unique_ptr<BotMap> botMap(new BotMap());
	std::unique_ptr<PlayerMap> playerMap(new PlayerMap());
	std::shared_ptr<Ship> ship(new Ship());

	do { // Work until switch every case
		systemClear();
		help();
		ship->resetPosition();

		playerMap->showMapName();	
		playerMap->showMap();

		botMap->showMapName();
		botMap->showMap();

		ship->showShipsSelection();	

		//----------PLAYER----------//	
		switch(playerSelect()) { // Player chooses which ship he wants to put into the map
		case '1':
			if(!playerMap->isShipOnMap(1)) {
				playerMap->shipIsOnMap(1);
				do {
					systemClear();
					help();

					playerMap->setShip(ship->getShip1(), ship->getShipIsRotated(), ship->getShipPositionX(), ship->getShipPositionY());
	
					playerMap->showMapName();
					playerMap->showMap();

					botMap->showMapName();
					botMap->showMap();
	
					ship->showShipsSelection();
					ship->setShipsPosition(ship->getShip1(), *Map::getMapSizeWidth(), *Map::getMapSizeHeight(), playerMap->getVecMap2D());
		
					if(ship->getShipIsMoved())
						playerMap->resetOldShipPosition(ship->getShip1(), ship->getShipIsRotated(), ship->getOldShipPositionX(), ship->getOldShipPositionY(), ship->getMoveX(), ship->getShipPositionX(), ship->getShipPositionY());	
				} while(ship->getMoveX() != 0 || ship->getMoveY() != 0);
			}
		break;
		case '2':
			if(!playerMap->isShipOnMap(2)) {
				playerMap->shipIsOnMap(2);
				do {
		                        systemClear();
		                        help(); 

		                        playerMap->setShip(ship->getShip2(), ship->getShipIsRotated(), ship->getShipPositionX(), ship->getShipPositionY());
 
		                        playerMap->showMapName();
		                        playerMap->showMap();
 
		                        botMap->showMapName();
		                        botMap->showMap();

		                        ship->showShipsSelection();
		                        ship->setShipsPosition(ship->getShip2(), *Map::getMapSizeWidth(), *Map::getMapSizeHeight(), playerMap->getVecMap2D());

		                        if(ship->getShipIsMoved())
			                        playerMap->resetOldShipPosition(ship->getShip2(), ship->getShipIsRotated(), ship->getOldShipPositionX(), ship->getOldShipPositionY(), ship->getMoveX(), ship->getShipPositionX(), ship->getShipPositionY());
		                 } while(ship->getMoveX() != 0 || ship->getMoveY() != 0);
			}
		break;
		case '3':
			if(!playerMap->isShipOnMap(3)) {
				playerMap->shipIsOnMap(3);
				do {
	        	                systemClear();
		                        help();
 
		                        playerMap->setShip(ship->getShip3(), ship->getShipIsRotated(), ship->getShipPositionX(), ship->getShipPositionY());
 
		                        playerMap->showMapName();
		                        playerMap->showMap();
 
		                        botMap->showMapName();
		                        botMap->showMap();
 
		                        ship->showShipsSelection();
		                        ship->setShipsPosition(ship->getShip3(), *Map::getMapSizeWidth(), *Map::getMapSizeHeight(), playerMap->getVecMap2D());
 
		                        if(ship->getShipIsMoved())
		                                playerMap->resetOldShipPosition(ship->getShip3(), ship->getShipIsRotated(), ship->getOldShipPositionX(), ship->getOldShipPositionY(), ship->getMoveX(), ship->getShipPositionX(), ship->getShipPositionY());
		                 } while(ship->getMoveX() != 0 || ship->getMoveY() != 0);
			}
		break;
		case '4':
			if(!playerMap->isShipOnMap(4)) {
				playerMap->shipIsOnMap(4);
				do {
		                        systemClear();
		                        help();
   
		                        playerMap->setShip(ship->getShip4(), ship->getShipIsRotated(), ship->getShipPositionX(), ship->getShipPositionY());
   
		                        playerMap->showMapName();
		                        playerMap->showMap();
	   
		                        botMap->showMapName();
		                        botMap->showMap();
	   
		                        ship->showShipsSelection();
		                        ship->setShipsPosition(ship->getShip4(), *Map::getMapSizeWidth(), *Map::getMapSizeHeight(), playerMap->getVecMap2D());
	   
		                        if(ship->getShipIsMoved())
		                                playerMap->resetOldShipPosition(ship->getShip4(), ship->getShipIsRotated(), ship->getOldShipPositionX(), ship->getOldShipPositionY(), ship->getMoveX(), ship->getShipPositionX(), ship->getShipPositionY());
		                 } while(ship->getMoveX() != 0 || ship->getMoveY() != 0);
			}
		break;
		case '5':
			if(!playerMap->isShipOnMap(5)) {
				playerMap->shipIsOnMap(5);
				do {
		                        systemClear();
		                        help();
	    
		                        playerMap->setShip(ship->getShip5(), ship->getShipIsRotated(), ship->getShipPositionX(), ship->getShipPositionY());
		    
		                        playerMap->showMapName();
		                        playerMap->showMap();
	   
		                        botMap->showMapName();
		                        botMap->showMap();
	   
		                        ship->showShipsSelection();
		                        ship->setShipsPosition(ship->getShip5(), *Map::getMapSizeWidth(), *Map::getMapSizeHeight(), playerMap->getVecMap2D());
	   
		                        if(ship->getShipIsMoved())
		                                playerMap->resetOldShipPosition(ship->getShip5(), ship->getShipIsRotated(), ship->getOldShipPositionX(), ship->getOldShipPositionY(), ship->getMoveX(), ship->getShipPositionX(), ship->getShipPositionY());
		                 } while(ship->getMoveX() != 0 || ship->getMoveY() != 0);
			}
		break;
		default:
		break;
		}
	} while((playerMap->getVecShipOnMap()).size() != ship->getShipMaxCount());

	//-----------AI-----------//

}

void GameManager::help() {
	cout << "\u25A0-ship, X-hit, O-miss, '@' -ship on the ship ' '-free." << endl << endl;
}
/*----------START-END------------*/

/*-----------SETTINGS------------*/
void GameManager::settings() {
	do {
		systemClear();
		showSettingsMenu();
		switch(playerSelect()) {
			case '1':
				setDifficultyLevel();
			break;
			case '2':
				setMapSize();
			break;
			case '3':
				setExit();	
			break;
			default:
				systemClear();
			break;	
		}		
	} while(exit == false);	
	exit = false;
}

void GameManager::showSettingsMenu() {
	cout << "---- CURRENT SETTINGS ----" << endl;
	cout << "1.Difficulty level: " << *Ai::getDifficultyLevel() << "  (EASY, MEDIUM, HARD)" << endl;
	cout << "2.Map height:" << *Map::getMapSizeHeight() << ", width:" << *Map::getMapSizeWidth() << "   (5-15)" << endl;	
	cout << "3.Back" << endl;
}

void GameManager::setDifficultyLevel() {
	cout << "Write capital letters!" << endl;
	do {	
		wrongInput(*Ai::getDifficultyLevel());
		
		cout << "Change:";
		cin >> *Ai::getDifficultyLevel();
	} while(*Ai::getDifficultyLevel() != "EASY" && *Ai::getDifficultyLevel() != "MEDIUM" && *Ai::getDifficultyLevel() != "HARD");
}

void GameManager::setMapSize() {	
	cout << "Choose between (5-15)!" << endl;
	do {
		wrongInput(*Map::getMapSizeHeight());
		cout << "Change height:";
		cin >> *Map::getMapSizeHeight();
	}while(*Map::getMapSizeHeight() < 5 || *Map::getMapSizeHeight() > 15);

	do {
		wrongInput(*Map::getMapSizeWidth());
		cout << "Change width:";
		cin >> *Map::getMapSizeWidth();
	} while(*Map::getMapSizeWidth() < 5 || *Map::getMapSizeWidth() > 15);
}

void GameManager::wrongInput(std::string inputDifficult) {
	if(inputDifficult != "EASY" && inputDifficult != "MEDIUM" && inputDifficult != "HARD")
		cout << "Wrong input! ";
}

void GameManager::wrongInput(int inputNumber) {
	if(inputNumber < 5 || inputNumber > 15)
	        cout << "Wrong input! ";
}

/*--------SETTINGS-END---------*/
