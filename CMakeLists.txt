cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)

project ("python-format-operator-remake")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS include/*.hpp)

add_executable (python-format-operator-remake ${SOURCES} ${HEADERS})
target_include_directories(python-format-operator-remake PRIVATE include)
