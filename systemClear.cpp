#include <cstdlib>
#include "systemClear.h"

void systemClear() {
#ifdef WINDOWS
	std::system("cls");
#else
	std::system("clear");
#endif
}
