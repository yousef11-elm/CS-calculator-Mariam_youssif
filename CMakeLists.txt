cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CS2_Calculator)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
add_library(calculator STATIC calculator.cpp)

# Create executable
add_executable(calculator_test test.cpp)

# Link libraries
target_link_libraries(calculator_test calculator)