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

add_subdirectory(src)
