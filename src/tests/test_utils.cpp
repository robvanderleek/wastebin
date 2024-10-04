#include <catch2/catch_test_macros.hpp>
#include "../utils.hpp"

namespace wastebin {

    TEST_CASE("Get version", "[Test]") {
        std::string result = version();

        REQUIRE(result == "wastebin v0.1");
    }

    TEST_CASE("Test case 2", "[Test]") {
        REQUIRE(2 == 2);
    }

}