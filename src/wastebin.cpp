#include <filesystem>
#include "CLI/CLI.hpp"
#include "utils.hpp"

int main(int argc, const char *argv[]) {
    std::filesystem::path wastebinRoot("/Users/rob/Desktop/wastebin");

    CLI::App app("A wastebin for your shell");
    std::vector<std::string> paths;
    app.add_flag("--version", wastebin::print_version, "Print version");
    app.add_option("paths", paths, "Paths to move to wastebin")->check(CLI::ExistingPath);
    CLI11_PARSE(app, argc, argv);

    if (paths.empty()) {
        for (const auto &entry: std::filesystem::directory_iterator(wastebinRoot))
            std::cout << entry.path().filename() << std::endl;
        return 0;
    }

    for (const auto &path: paths) {
        std::cout << "Path: " << path << std::endl;
        std::filesystem::path absPath = std::filesystem::absolute(path);
        bool isFile = std::filesystem::is_regular_file(absPath);
        std::cout << "Filename: " << absPath.filename() << std::endl;
        std::cout << "Absolute path: " << absPath << std::endl;

        std::filesystem::path targetPath;
        targetPath = wastebinRoot / absPath.filename();
        std::filesystem::rename(absPath, targetPath);
        std::cout << "Moved to: " << targetPath << std::endl;
    }

//
    return 0;
}
