#include <iostream>
#include "version.h"

void usage()
{
    std::cout << "A wastebin for your shell" << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "  wb <path1> <path2> ... <pathN>" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "path: paths to move to wastebin" << std::endl;
    std::cout << "--version: print version" << std::endl;
}

std::string sayHello()
{
    return {"hello world!"};
}

int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        usage();
        return 0;
    }
    if (std::string(argv[1]) == "--version")
    {
        std::cout << "wastebin version " << WASTEBIN_VERSION << std::endl;
        return 0;
    }
    std::cout << sayHello() << std::endl;
    return 0;
}
