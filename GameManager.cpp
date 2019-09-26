#include <iostream>
#include <memory>
#include <string>
#include <random>

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
	std::unique_ptr<Ai> ai(new Ai());

	playerHitCounter = 0;
	botHitCounter = 0;

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
	ai->setPosition(ship->getShip5(), *Map::getMapSizeWidth(), *Map::getMapSizeHeight(), botMap->getVecMap2D());
	botMap->setShip(ai->getBotShipPosition(), ai->getIsRotateVec(), ship->getShip5());

	ai->setPosition(ship->getShip4(), *Map::getMapSizeWidth(), *Map::getMapSizeHeight(), botMap->getVecMap2D());
	botMap->setShip(ai->getBotShipPosition(), ai->getIsRotateVec(), ship->getShip4());

	ai->setPosition(ship->getShip3(), *Map::getMapSizeWidth(), *Map::getMapSizeHeight(), botMap->getVecMap2D());
	botMap->setShip(ai->getBotShipPosition(), ai->getIsRotateVec(), ship->getShip3());

	ai->setPosition(ship->getShip2(), *Map::getMapSizeWidth(), *Map::getMapSizeHeight(), botMap->getVecMap2D());
	botMap->setShip(ai->getBotShipPosition(), ai->getIsRotateVec(), ship->getShip2());

	ai->setPosition(ship->getShip1(), *Map::getMapSizeWidth(), *Map::getMapSizeHeight(), botMap->getVecMap2D());
	botMap->setShip(ai->getBotShipPosition(), ai->getIsRotateVec(), ship->getShip1());
	
	//-----------GAME-----------//
	
	whoStartGame();
	
	do {
		systemClear();
	        help();

	        playerMap->showMapName();
	        playerMap->showMap();
 
	        botMap->showMapName();
	        botMap->showMap();

		if(playerStart) {
			playerStart = false;
			playerRound(botMap->getVecMap2D(), *Map::getMapSizeWidth(), *Map::getMapSizeHeight());
		}
		else {
			playerStart = true;
			botRound(playerMap->getVecMap2D(), ai->randomHit(playerMap->getVecMap2D(), *Map::getMapSizeWidth(), *Map::getMapSizeHeight()));
		}
		checkWin(botMap->getVecMap2D(), playerMap->getVecMap2D(), *Map::getMapSizeWidth(), *Map::getMapSizeHeight());

	} while(!playerWin && !botWin);

	systemClear();
        help();
 
        playerMap->showMapName();
        playerMap->showMap();

        botMap->showMapName();
        botMap->showMap();

	if(playerWin)
		playerIsWinner();
	else
		botIsWinner();

	do {
		cout << "0. Return to MENU" << endl;
		playerSelect();
	} while(select != '0');
}

void GameManager::help() {
	cout << "'\u25A0' -ship, 'X' -hit, 'O' -miss, '@' -ship on the ship, ' ' -free." << endl << endl;
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
	cout << "2.Map height:" << *Map::getMapSizeHeight() << ", width:" << *Map::getMapSizeWidth() << "   (6-15)" << endl;	
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
	cout << "Choose between (6-15)!" << endl;
	do {
		wrongInput(*Map::getMapSizeHeight());
		cout << "Change height:";
		cin >> *Map::getMapSizeHeight();
	}while(*Map::getMapSizeHeight() < 6 || *Map::getMapSizeHeight() > 15);

	do {
		wrongInput(*Map::getMapSizeWidth());
		cout << "Change width:";
		cin >> *Map::getMapSizeWidth();
	} while(*Map::getMapSizeWidth() < 6 || *Map::getMapSizeWidth() > 15);
}

void GameManager::wrongInput(std::string inputDifficult) {
	if(inputDifficult != "EASY" && inputDifficult != "MEDIUM" && inputDifficult != "HARD")
		cout << "Wrong input! ";
}

void GameManager::wrongInput(int inputNumber) {
	if(inputNumber < 6 || inputNumber > 15)
	        cout << "Wrong input! ";
}

/*--------SETTINGS-END---------*/

/*--------GAME-MANAGER--------*/
void GameManager::whoStartGame() {
	std::random_device rd;
	std::mt19937 gen(rd());

	std::bernoulli_distribution randBool(0.5); //change if harder
	
	playerStart = randBool(gen);
}

void GameManager::botIsWinner() {
	cout << "The winner is: BOT!" << endl;	
}

void GameManager::playerIsWinner() {
	cout << "The winner is: Player!" << endl;
}

void GameManager::playerRound(std::vector<std::vector<int>>* botMap, unsigned int& widthMax, unsigned int& heightMax) {
	char inputLetter;
	int inputLetterNumber;
	int inputNumber;	
	bool hit;

	cout << "Friendly dead ships: " << botHitCounter << "/15" << endl;
	cout << "Enemy dead ships: " << playerHitCounter << "/15" << endl << endl;

	do {
		hit = false;
		do {
			cout << "Select letter: ";
			cin >> inputLetter;
		} while(isCorrectLetter(inputLetter, widthMax));
		
		do {
			cout << "Select number: ";
			cin >> inputNumber;
		} while(inputNumber < 1 || inputNumber > heightMax);

		if(inputLetter <= 90) //convert capital letter to map's area
			inputLetterNumber = (int)inputLetter - 65; 
		else // convert miniscule letter to map's area
			inputLetterNumber = (int)inputLetter - 97;

		if((*botMap)[inputLetterNumber][inputNumber - 1] != 1 && (*botMap)[inputLetterNumber][inputNumber - 1] != 3) { // 1 = miss, 3 = hit
			(*botMap)[inputLetterNumber][inputNumber - 1] += 1;
			hit = true;
		}
		
		if((*botMap)[inputLetterNumber][inputNumber - 1] == 3) {
			playerHitCounter++;
			playerStart = true;
		}
	} while(hit != true);
}

void GameManager::botRound(std::vector<std::vector<int>>* vecMap2D, std::vector<int>* randHit) {
	(*vecMap2D)[(*randHit)[0]][(*randHit)[1]] += 1;
	(*randHit).clear();

	if((*vecMap2D)[(*randHit)[0]][(*randHit)[1]] == 3) {
		botHitCounter++;
		playerStart = false;
	}
}

void GameManager::checkWin(std::vector<std::vector<int>>* botMap , std::vector<std::vector<int>>* playerMap, unsigned int& widthMax, unsigned int& heightMax) {
	int botCounter = 0, playerCounter = 0;
	playerWin = false;
	botWin = false;

	for(int i = 0; i < heightMax; i++) { //Vertical
                for(int j = 0; j < widthMax; j++) { //Horizontal
			if((*botMap)[j][i] == 3) //hit
				playerCounter++;
			if((*playerMap)[j][i] == 3) { 
				botCounter++;
			}
		}
	}
       
	if(playerCounter == 15) // max ships area 
		playerWin = true;
	
	if(botCounter == 15)
		botWin = true;
}

bool GameManager::isCorrectLetter(char& inputLetter, unsigned int& widthMax) {
	if((inputLetter >= 'A' && inputLetter <= (char)(widthMax) + 64) || (inputLetter >= 'a' && inputLetter <= (char)(widthMax + 96)))
                return false;
        else
                return true;
}
/*------GAME-MANAGER-END--------*/
