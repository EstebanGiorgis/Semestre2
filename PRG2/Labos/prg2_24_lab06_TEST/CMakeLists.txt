cmake_minimum_required(VERSION 3.28)
project(prg2_24_lab06_TEST C)

set(CMAKE_C_STANDARD 17)

add_executable(PRG2_unions_structs src/command_ship.c src/cargo_ship.c src/combat_ship.c src/main.c src/ship.c)
