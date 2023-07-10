project(WindowClock)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDART 20)

set(SOURCES
  main.cpp
  clock.cpp
  clock.h
  clock_app.cpp
  clock_app.h
)

find_package(SDL2 REQUIRED)
include_directories(WindowClock ${SDL2_INCLUDE_DIRS})

add_executable(WindowClock ${SOURCES})
target_link_libraries(WindowClock ${SDL2_LIBRARIES} GL)
