cmake_minimum_required(VERSION 3.5.0)
project(engine VERSION 0.1.0 LANGUAGES C CXX)


add_library(engine STATIC
    src/baseEngine.cpp
)

target_include_directories(engine PUBLIC include)