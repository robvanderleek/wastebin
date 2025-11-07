#include <catch2/catch_test_macros.hpp>
#include "../utils.hpp"

namespace wastebin {

    TEST_CASE("Get version", "[Test]") {
        std::string result = version();

        REQUIRE(result == "0.1");
    }

}