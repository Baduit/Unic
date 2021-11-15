#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

void thrower()
{
	throw 5;
}

TEST_CASE("Example")
{
	CHECK(1 == 1);
	CHECK_MESSAGE(true, "A message");

	SUBCASE("my subcase")
    {
		REQUIRE(5 == 5);
    }
}
