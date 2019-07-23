#include <string>

class Map;
class Ai;

class GameManager {
public:
	GameManager() = default;
	~GameManager() = default;

	char menu();
	void settings(std::shared_ptr<Map> map, std::shared_ptr<Ai> ai);
	bool startGame(std::shared_ptr<Map> map, std::shared_ptr<Ai> ai);
	//Exit
	void setExit() { exit = true; }	
	bool getExit() { return exit; }
private:
	//Settings
	void showSettingsMenu(std::shared_ptr<Map> map, std::shared_ptr<Ai> ai);
	void setDifficultyLevel(std::shared_ptr<Ai> ai);
	void setMapSize(std::shared_ptr<Map> map);
	//Menu
	void showMenu();
	//Others
	char playerSelect();
	char select;
	bool exit;
};
