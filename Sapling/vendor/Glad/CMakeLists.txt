cmake_minimum_required(VERSION 3.16)
project(Glad)

add_library(Glad include/glad/gl.h src/gl.c)
target_include_directories(Glad PRIVATE include/)