cmake_minimum_required(VERSION 4.4)
project(myshell C)

set(CMAKE_C_STANDARD 23)

add_executable(myshell main.c
        src/navigation.c
        src/system.c
        include/commands.h
        src/files.c)
