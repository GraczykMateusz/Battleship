#include <string>

class Ai {
public:
	Ai();
	~Ai() = default;

	std::string* getDifficultyLevel() { return &difficultyLevel; }
private:
	std::string difficultyLevel;
};
