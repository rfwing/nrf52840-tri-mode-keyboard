cmake_minimum_required(VERSION 3.20.0)
include_directories(inc)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(Keyboard)

target_sources(app PRIVATE src/main.c)
