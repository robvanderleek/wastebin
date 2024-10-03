#include <iostream>

#include "binlib.hpp"
#include "config.hpp"

using namespace std;

namespace binlib {

    void version() {
        auto message = "wastebin v";
        cout << message << wastebin_VERSION_MAJOR << "." <<
            wastebin_VERSION_MINOR << endl;
    }

}
