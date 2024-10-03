configure_file(config.hpp.in config.hpp)
add_library(binlib binlib.cpp)
target_include_directories(binlib PUBLIC "${PROJECT_BINARY_DIR}/binlib")
