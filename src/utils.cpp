#include <iostream>

#include "config.hpp"

namespace wastebin {

    std::string version() {
        return std::to_string(wastebin_VERSION_MAJOR) + "." +
               std::to_string(wastebin_VERSION_MINOR);
    }

    void print_version(std::size_t c) {
        std::cout << std::string("wastebin v") << version() << std::endl;
    }

} // wastebin
