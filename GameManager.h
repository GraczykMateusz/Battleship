#include <string>

class Map;
class Ai;
class Ship;

class GameManager {
public:
	GameManager() = default;
	~GameManager() = default;

	//Others
	char menu();
	void settings();
	bool startGame();

	//Exit
	void setExit() { exit = true; }	
	bool getExit() { return exit; }
private:
	//Settings
	void showSettingsMenu();
	void setDifficultyLevel();
	void setMapSize();

	//Menu
	void showMenu();

	//Input/Select
	void wrongInput(std:: string inputDifficult);
	void wrongInput(int inputSize);
	char playerSelect();
	char select;

	//Others
	void help();
	bool exit;
};
