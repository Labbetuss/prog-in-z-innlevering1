cmake_minimum_required(VERSION 3.6)
project(prog_in_z_innlevering1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES sortNames.c)
add_executable(prog_in_z_innlevering1 ${SOURCE_FILES})