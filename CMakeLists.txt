cmake_minimum_required(VERSION 3.25)
project(Rayska)

set(CMAKE_CXX_STANDARD 20)

add_executable(Rayska main.cpp writer.hpp vec3d.hpp vec3d.cpp ray.hpp ray.cpp)
