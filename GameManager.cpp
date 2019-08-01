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
	cout << "Select: ";
	cin >> select;
	return select;
}
/*----------MENU-END-------------*/

/*------------START--------------*/
bool GameManager::startGame() {
	std::unique_ptr<BotMap> botMap(new BotMap());
	std::unique_ptr<PlayerMap> playerMap(new PlayerMap());
	std::shared_ptr<Ship> ship(new Ship());

	systemClear();
	help();
	
	playerMap->showMapName();	
	playerMap->showMap();

	botMap->showMapName();
	botMap->showMap();

	ship->showShipsSelection();	
	
	switch(playerSelect()) { //Player chooses which ship he wants to put into the map
	case '1':
		do {
			systemClear();
			help();

			playerMap->setShipsOnMap(ship->getShip1());

			playerMap->showMapName();
			playerMap->showMap();

			botMap->showMapName();
			botMap->showMap();

			ship->showShipsSelection();
			
			cin >> input;
		} while(input != 'q');
	break;
	case '2':
	break;
	case '3':
	break;
	case '4':
	break;
	case '5':
	break;
	default:
	break;
	}
}

void GameManager::help() {
	cout << "\u25A0-ship, X-hit, O-miss, ' '-free." << endl << endl;
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
	cout << "Select:";
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
