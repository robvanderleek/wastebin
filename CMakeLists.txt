cmake_minimum_required(VERSION 3.29.6)

project(wastebin VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.3.2
        GIT_SHALLOW ON
)

FetchContent_MakeAvailable(Catch2)

FetchContent_Declare(
        cli11_proj
        QUIET
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
        GIT_TAG v2.4.2
)

FetchContent_MakeAvailable(cli11_proj)

add_subdirectory(src)
