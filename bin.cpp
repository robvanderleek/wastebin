#include <iostream>

#include "config.hpp"

using namespace std;

int main(int argc, const char *argv[]) {
    auto message = "wastebin v";
    cout << message << wastebin_VERSION_MAJOR << "." << 
        wastebin_VERSION_MINOR << endl;
    return 0;
}
