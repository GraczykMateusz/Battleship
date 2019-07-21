//FILENAME: main.cpp
#include <iostream>
#include <memory>
#include "Map.h"
#include "GameManager.h"
#include "systemClear.h"
#include "Ai.h"

int main() {
	std::unique_ptr<GameManager> gameManager(new GameManager());
	std::shared_ptr<Map> map(new Map(gameManager->getMapSize()));
	std::shared_ptr<Ai> ai(new Ai(gameManager->getDifficultyLevel()));
	do {
		systemClear();
		switch (gameManager->menu()) {
			case '1':
				systemClear();
				gameManager->startGame();
			break;
			case '2':
				systemClear();
				gameManager->settings(map, ai);
			break;	
			case '3':
				systemClear();
				gameManager->setExit();
			break;
			default:
				systemClear();
			break;
		}
	} while(gameManager->getExit() == false);
	return 0;
}
