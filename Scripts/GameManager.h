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

	void playerRound(std::vector<std::vector<int>>* botMap, unsigned int& widthMax, unsigned int& heightMax);
	void botRound(std::vector<std::vector<int>>* vecMap2D, std::vector<int>* randHit);

	short playerHitCounter;
	short botHitCounter;
	void checkWin(std::vector<std::vector<int>>* botMap , std::vector<std::vector<int>>* playerMap, unsigned int& widthMax, unsigned int& heightMax);
	bool isCorrectLetter(char& inputLetter, unsigned int& widthMax);

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
