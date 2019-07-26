#include <string>

class Ai {
public:
	Ai();
	~Ai() = default;

	static std::string* getDifficultyLevel();
private:
	static std::string difficultyLevel;
};
