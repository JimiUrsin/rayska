cmake_minimum_required(VERSION 3.25)
project(Rayska)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-fopenmp")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(Rayska main.cpp core/writer.hpp core/vec3d.hpp core/vec3d.cpp core/ray.hpp core/ray.cpp hittables/hittable.hpp hittables/sphere.hpp hittables/sphere.cpp hittables/hittable_list.hpp hittables/hittable_list.cpp core/common.hpp core/camera.hpp core/camera.cpp materials/material.hpp materials/diffuse.hpp materials/diffuse.cpp materials/metal.hpp materials/metal.cpp materials/glass.hpp materials/glass.cpp)

find_package(OpenMP)

if(OpenMP_CXX_FOUND)
    target_link_libraries(Rayska PUBLIC OpenMP::OpenMP_CXX)
endif()
