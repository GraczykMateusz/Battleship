#include <cstdlib>

void systemClear() {
#ifdef WINDOWS
	std::system("cls");
#else
	std::system("clear");
#endif
}
