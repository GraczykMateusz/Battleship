//FILENAME: GameManager.h
#include <string>

class GameManager {
public:
	GameManager();
	~GameManager() = default;

	short menu();
	short settings();
	bool startGame();
	void setExit();
	
	int getMapSize() { return mapSizeGM; }
	std::string getDificultyLevel() { return dificultyLevel; }
	bool getExit() { return exit; }
private:
	//Settings
	int mapSizeGM;
	std::string dificultyLevel;
	//Menu
	void showMenu();
	int selectMenu();
	//Others
	int select;
	bool exit;
};
