cmake_minimum_required(VERSION 3.16)
project(charcoal)

set(CMAKE_CXX_STANDARD 11)

add_executable(charcoal console.cpp view.cpp render.cpp ergodox.hpp ergodox.cpp main.cpp )