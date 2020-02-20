cmake_minimum_required(VERSION 3.14)

project(Calculator)

set(CMAKE_CXX_STANDARD 17)

add_library(CalcLib STATIC Calc.h Calc.cpp)

add_executable(Calculator main.cpp)

target_link_libraries(Calculator CalcLib)
