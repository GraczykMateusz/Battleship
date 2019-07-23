#include <iostream>
#include <memory>
#include "Map.h"
#include "GameManager.h"
#include "systemClear.h"
#include "Ai.h"

int main() {
	std::shared_ptr<Map> map(new Map());
	std::shared_ptr<Ai> ai(new Ai());
	std::unique_ptr<GameManager> gameManager(new GameManager());
	do {
		systemClear();
		switch (gameManager->menu()) {
			case '1':	
				gameManager->startGame(map, ai);
			break;
			case '2':
				gameManager->settings(map, ai);
			break;	
			case '3':
				gameManager->setExit();
			break;
			default:
			break;
		}
	} while(gameManager->getExit() == false);
	return 0;
}
