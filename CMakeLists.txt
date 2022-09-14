cmake_minimum_required(VERSION 3.17)
project(philo C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(philo
        colors.h
        commands.c
        init.c
        main.c
        phil.h
        utils.c)
