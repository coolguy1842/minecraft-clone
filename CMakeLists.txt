cmake_minimum_required(VERSION 3.5.0)
project(game VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory("include")

include(CTest)
enable_testing()

set(PROJECT_SOURCE
    src/main.cpp
)

include_directories(src/include)
add_executable(game ${PROJECT_SOURCE})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(game engine SDL2 OpenGL::GL ${GLEW_LIBRARIES})