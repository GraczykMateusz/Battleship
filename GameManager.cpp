#include <iostream>
#include <memory>
#include <string>
#include "GameManager.h"
#include "Map.h"
#include "Ai.h"
#include "systemClear.h"

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
bool GameManager::startGame(std::shared_ptr<Map> map, std::shared_ptr<Ai> ai) {
	systemClear();
	//-----------------------
	//Here AI set ships on the map
	//------------------------
	
	map->showMap();
}
/*----------START-END------------*/

/*-----------SETTINGS------------*/
void GameManager::settings(std::shared_ptr<Map> map, std::shared_ptr<Ai> ai) {
	do {
		systemClear();
		showSettingsMenu(map, ai);
		switch(playerSelect()) {
			case '1':
				setDifficultyLevel(ai);
			break;
			case '2':
				setMapSize(map);
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

void GameManager::showSettingsMenu(std::shared_ptr<Map> map, std::shared_ptr<Ai> ai) {
	cout << "---- CURRENT SETTINGS ----" << endl;
	cout << "1.Difficulty level: " << *ai->getDifficultyLevel() << "  (EASY, MEDIUM, HARD)" << endl;
	cout << "2.Map height:" << *map->getMapSizeHeight() << ", width:" << *map->getMapSizeWidth() << "   (10-20)" << endl;	
	cout << "3.Back" << endl;
	cout << "Select:";
}

void GameManager::setDifficultyLevel(std::shared_ptr<Ai> ai) {
	cout << "Change:";
	auto difficultyLevel = ai->getDifficultyLevel();
	cin >> *difficultyLevel;
}

void GameManager::setMapSize(std::shared_ptr<Map> map) {
	auto mapSizeHeight = map->getMapSizeHeight();
	auto mapSizeWidth = map->getMapSizeWidth();
	
	cout << "Change height:";
	cin >> *mapSizeHeight;

	cout << "Change width:";
	cin >> *mapSizeWidth;
	
	map->setVecMap2D();
}
/*--------SETTINGS-END---------*/
