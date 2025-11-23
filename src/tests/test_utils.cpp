#include <iostream>
#include <catch2/catch_test_macros.hpp>

#include "../utils.hpp"

TEST_CASE("Get home directory", "[utils]")
{
    SECTION("Does not throw an exception")
    {
        REQUIRE_NOTHROW(getHomeDirectory());
    }

    SECTION("Result is not empty")
    {
        std::string homedir = getHomeDirectory();

        REQUIRE(!homedir.empty());
    }
}
