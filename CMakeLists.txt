cmake_minimum_required(VERSION 3.13)
project(GOFISH)

set(CMAKE_CXX_STANDARD 11)

add_executable(GOFISH go_fish.cpp card.h deck.h player.h player.cpp deck.cpp card.cpp)