cmake_minimum_required(VERSION 3.15)
project(unilib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find pybind11
find_package(pybind11 REQUIRED)

# Python module
pybind11_add_module(unilib src/bindings.cpp)
target_include_directories(unilib PUBLIC include)

# Install rules
install(TARGETS unilib LIBRARY DESTINATION .)
install(DIRECTORY include/unilib DESTINATION include)
