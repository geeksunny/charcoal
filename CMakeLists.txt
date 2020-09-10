cmake_minimum_required(VERSION 3.16)
project(charcoal)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)

add_executable(charcoal
        console.cpp
        view.cpp
        render.cpp
        ergodox.hpp
        ergodox.cpp
        main.cpp
        qmk.h
        qmk_rgb_matrix_types.h
        qmk_led_types.h
        ergodox_ez_values.h
        qmk_rgb.h
        qmk_rgb.cpp
        ergodox_ez_config.h
        ergodox_ez_config.cpp
        )
target_compile_options (charcoal PRIVATE -Wall -Wextra -Wpedantic)
