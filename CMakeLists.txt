cmake_minimum_required(VERSION 3.5.0)
project(Calculator VERSION 0.1.0 LANGUAGES C CXX)


set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_executable(Calculator main.cpp)


add_subdirectory(googletest)
include_directories(googletest/googletest/include)

enable_testing()
add_executable(calculator_tests TestCalculator.cpp)
target_link_libraries(calculator_tests gtest gtest_main)
add_test(NAME CalculatorTests COMMAND calculator_tests)

