CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project (htaccess-checker CXX)

# Add source directory
add_subdirectory (src)

# Generate executables from src
add_executable (htac src/htac.cpp)
target_link_libraries (htac htaccess-checker curl)