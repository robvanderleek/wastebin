#include <iostream>
#include <filesystem>
#include "utils.hpp"
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
    const auto homedir = getHomeDirectory();

    const auto wastebinDir = std::filesystem::path(homedir) / "mywastebin";
    if (!std::filesystem::exists(wastebinDir))
    {
        std::cout << "Creating wastebin directory at " << wastebinDir << std::endl;
        std::filesystem::create_directory(wastebinDir);
    }

    for (int i = 1; i < argc; i++)
    {
        auto p = std::filesystem::path(argv[i]);
        if (!std::filesystem::exists(p))
        {
            std::cout << "Path " << p << " does not exist, skipping." << std::endl;
            continue;
        }
        auto dest = wastebinDir / p.filename();
        std::cout << "Moving " << p << " to " << dest << std::endl;
        std::filesystem::rename(p, dest);
        std::cout << "Done." << std::endl;
    }

    return 0;
}
