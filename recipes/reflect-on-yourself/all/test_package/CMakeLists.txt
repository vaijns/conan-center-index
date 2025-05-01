cmake_minimum_required(VERSION 3.30)
project(test_package LANGUAGES CXX)

find_package(reflect-on-yourself REQUIRED CONFIG)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE test_package.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
target_link_libraries(${PROJECT_NAME} PRIVATE reflect-on-yourself::reflect-on-yourself)
