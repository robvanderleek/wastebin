#include <iostream>

#include "config.hpp"

namespace wastebin {

    std::string version() {
        std::string result = "wastebin v";
        return result + std::to_string(wastebin_VERSION_MAJOR) + "." +
               std::to_string(wastebin_VERSION_MINOR);
    }

} // wastebin
