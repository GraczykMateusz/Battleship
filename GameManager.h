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
	//Game
	void whoStartGame();
	bool playerStart;

	bool playerWin;
	void playerIsWinner();
	bool botWin;
	void botIsWinner();

	void playerRound();
	void botRound(std::vector<std::vector<int>>* vecMap2D, std::vector<int>* randHit);

	void checkWin(std::vector<std::vector<int>>* botMap , std::vector<std::vector<int>>* playerMap, unsigned int widthMax, unsigned int heightMax);

	//Settings
	void showSettingsMenu();
	void setDifficultyLevel();
	void setMapSize();

	//Menu
	void showMenu();

	//Input/Select
	void wrongInput(std::string inputDifficult);
	void wrongInput(int inputSize);
	char playerSelect();
	char select;

	//Others
	void help();
	bool exit;
};
