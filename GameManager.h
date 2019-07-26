#include <string>

class Map;
class Ai;

class GameManager {
public:
	GameManager() = default;
	~GameManager() = default;

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
	//Others
	void wrongInput(std:: string inputDifficult);
	void wrongInput(int inputSize);
	char playerSelect();
	char select;
	bool exit;
};
