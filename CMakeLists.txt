cmake_minimum_required(VERSION 3.24)
project(wastebin VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
configure_file(src/version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/version.h @ONLY)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.3.2
        GIT_SHALLOW ON
)

FetchContent_MakeAvailable(Catch2)

set(MAIN_SOURCES
        src/utils.cpp
        src/utils.hpp
)

set(UNITTEST_SOURCES
        src/tests/test_utils.cpp
)

add_executable(${PROJECT_NAME} src/main.cpp ${MAIN_SOURCES})
add_executable(unittest ${MAIN_SOURCES} ${UNITTEST_SOURCES})
target_link_libraries(unittest PRIVATE Catch2::Catch2WithMain)

