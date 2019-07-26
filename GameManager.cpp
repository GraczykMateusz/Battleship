#include <iostream>
#include <memory>
#include <string>

#include "GameManager.h"
#include "Map.h"
#include "Ai.h"
#include "systemClear.h"
#include "BotMap.h"
#include "PlayerMap.h"

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
	cout << "Select:";
}

char GameManager::playerSelect() {
	cin >> select;
	return select;
}
/*----------MENU-END-------------*/

/*------------START--------------*/
bool GameManager::startGame() {
	systemClear();

	std::unique_ptr<BotMap> botMap(new BotMap());
	std::unique_ptr<PlayerMap> playerMap(new PlayerMap());
	
	playerMap->showMap();
	botMap->showMap();
		
	playerSelect();
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
	cout << "2.Map height:" << *Map::getMapSizeHeight() << ", width:" << *Map::getMapSizeWidth() << "   (10-20)" << endl;	
	cout << "3.Back" << endl;
	cout << "Select:";
}

void GameManager::setDifficultyLevel() {
	cout << "Change:";
	cin >> *Ai::getDifficultyLevel();
}

void GameManager::setMapSize() {	
	cout << "Change height:";
	cin >> *Map::getMapSizeHeight();

	cout << "Change width:";
	cin >> *Map::getMapSizeWidth();
}
/*--------SETTINGS-END---------*/
