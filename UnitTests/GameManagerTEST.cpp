#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE GameManagerTests
#include <boost/test/unit_test.hpp>
#include "../GameManager.cpp"

BOOST_AUTO_TEST_CASE( checkConstructor ) {
	GameManager gm;
	BOOST_CHECK(gm.getDificultyLevel() == "medium" && gm.getMapSize() == 10);
}
