configure_file(config.hpp.in config.hpp)

set(MAIN_SOURCES
        utils.cpp)

set(UNITTEST_SOURCES
        tests/test_utils.cpp)

add_executable(wb wastebin.cpp ${MAIN_SOURCES})
target_include_directories(wb PUBLIC "${PROJECT_BINARY_DIR}/src")
target_link_libraries(wb PRIVATE CLI11::CLI11)
install(TARGETS wb)

add_executable(unittests ${MAIN_SOURCES} ${UNITTEST_SOURCES})
target_include_directories(unittests PUBLIC "${PROJECT_BINARY_DIR}/src")
target_link_libraries(unittests PRIVATE Catch2::Catch2WithMain)
