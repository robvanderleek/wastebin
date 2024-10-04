#include <iostream>

#include "config.hpp"

namespace wastebin {

    void print_version(std::size_t c) {
        std::cout << std::string("wastebin v") + std::to_string(wastebin_VERSION_MAJOR) + "." +
                     std::to_string(wastebin_VERSION_MINOR) << std::endl;
    }

} // wastebin
