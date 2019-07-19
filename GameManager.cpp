//FILENAME: GameManager.cpp
#include <iostream>
#include "GameManager.h"

using std::cin;
using std::cout;
using std::endl;

GameManager::GameManager() {
	dificultyLevel = "medium";
	mapSizeGM = 10;
}

short GameManager::menu() {
	showMenu();
	return selectMenu();	
}

void GameManager::showMenu() {
	cout << "Welcome to BattleShip!" << endl;
	cout << "1.Start" << endl;
	cout << "2.Settings" << endl;
	cout << "3.Exit" << endl;
	cout << "Select:";
}

int GameManager::selectMenu() {
	cin >> select;
	return select;
}

bool GameManager::startGame() {

}

short GameManager::settings() {

}

void GameManager::setExit() {
	exit = true;
}
