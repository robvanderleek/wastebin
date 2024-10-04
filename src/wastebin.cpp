#include <filesystem>
#include "utils.hpp"

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    std::filesystem::path file(argv[1]);
    std::cout << "Path: " << file << std::endl;
    std::filesystem::path absPath = std::filesystem::absolute(file);
    bool isFile = std::filesystem::is_regular_file(absPath);
    std::cout << "Filename: " << absPath.filename() << std::endl;
    std::cout << "Absolute path: " << absPath << std::endl;
    std::filesystem::path wastebinRoot("/Users/rob/Desktop/wastebin");
    std::filesystem::path targetPath;
    targetPath = wastebinRoot / absPath.filename();
    std::filesystem::rename(absPath, targetPath);
    std::cout << "Moved to: " << targetPath << std::endl;
    wastebin::version();
    return 0;
}
