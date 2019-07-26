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
