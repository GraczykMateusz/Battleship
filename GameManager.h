//FILENAME: GameManager.h
#include <string>

class Map;
class Ai;

class GameManager {
public:
	GameManager();
	~GameManager() = default;

	char menu();
	void settings(std::shared_ptr<Map> map, std::shared_ptr<Ai> ai);
	bool startGame();
	void setExit() { exit = true; }
	
	int getMapSize() { return mapSizeGM; }
	std::string getDifficultyLevel() { return difficultyLevelGM; }
	bool getExit() { return exit; }
private:
	//Settings
	int mapSizeGM;
	std::string difficultyLevelGM;
	void showSettingsMenu();
	void setDifficultyLevel(std::shared_ptr<Ai> ai);
	void setMapSize(std::shared_ptr<Map> map);
	//Menu
	void showMenu();
	//Others
	char playerSelect();
	char select;
	bool exit;
};
