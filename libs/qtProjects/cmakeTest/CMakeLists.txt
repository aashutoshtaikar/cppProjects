cmake_minimum_required(VERSION 2.8)

project(cmakeTest)

find_package (Threads)

add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
