#include <iostream>
#include <memory>
#include "Map.h"
#include "GameManager.h"
#include "systemClear.h"
#include "Ai.h"

int main() {
	std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>();
	do {
		systemClear();
		switch (gameManager->menu()) {
			case '1':	
				gameManager->startGame();
			break;
			case '2':
				gameManager->settings();
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
