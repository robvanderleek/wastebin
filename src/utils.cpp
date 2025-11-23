#include <string>

int add(const int a, const int b)
{
    return a + b;
}

std::string getHomeDirectory()
{
    const char *homedir = std::getenv("HOME");
    if (homedir)
    {
        return homedir;
    }
    throw std::runtime_error("no home directory");
}
