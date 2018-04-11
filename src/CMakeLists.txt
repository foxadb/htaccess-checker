# Source files
file (GLOB LIB_HEADERS *.h)
file (GLOB LIB_SOURCES *.cpp)
add_library (htaccess-checker ${LIB_HEADERS} ${LIB_SOURCES})