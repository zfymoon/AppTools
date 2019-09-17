cmake_minimum_required(VERSION 3.14)
project(AppTools)

set(CMAKE_CXX_STANDARD 17)

add_executable(AppTools main.cpp shell.h log.h adb_wifi.h)