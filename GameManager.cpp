//FILENAME: GameManager.cpp
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

GameManager::GameManager() {
	difficultyLevelGM = "medium";
	mapSizeGM = 10;
}

char GameManager::menu() {
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

bool GameManager::startGame() {

}
/*-----------SETTINGS------------*/
void GameManager::settings(std::shared_ptr<Map> map, std::shared_ptr<Ai> ai) {
	do {
		showSettingsMenu();
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

void GameManager::showSettingsMenu() {
	cout << "---- CURRENT SETTINGS ----" << endl;
	cout << "1.Difficulty level: " << difficultyLevelGM << "  (EASY, MEDIUM, HARD)" << endl;
	cout << "2.Map size: " << mapSizeGM << "  (10-20)" << endl;	
	cout << "3.Back" << endl;
	cout << "Select:";
}

void GameManager::setDifficultyLevel(std::shared_ptr<Ai> ai) {
	cout << "Change:";
}

void GameManager::setMapSize(std::shared_ptr<Map> map) {
	
}
