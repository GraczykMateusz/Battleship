#include <iostream>
#include <memory>
#include "GameManager.h"
#include "Map.h"
#include "systemClear.cpp"

int main() {
	std::shared_ptr<GameManager> gameManager(new GameManager());
	std::unique_ptr<Map> map(new Map(gameManager->getMapSize()));
	do {
		switch (gameManager->menu()) {
			case 1:
				gameManager->startGame();
			break;
			case 2:
				gameManager->settings();
			break;	
			case 3:
				gameManager->setExit();
			break;
			default:
				systemClear();
			break;
		}
	} while(gameManager->getExit() == false);
	return 0;
}
