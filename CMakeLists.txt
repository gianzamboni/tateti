cmake_minimum_required(VERSION 2.8.12.2)
project(tateti)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -ggdb -lSDL2")

set(SOURCE_FILES Tateti/tateti.h Tateti/tateti.cpp  GUI/gui.h GUI/gui.cpp main.cpp)
add_executable(tateti ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES})