cmake_minimum_required(VERSION 3.25)
project(Rayska)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(SOURCES
    "main.cpp"
    "core/Writer.h"

)

add_executable(Rayska main.cpp core/Writer.h core/Vec3d.h core/Vec3d.cpp core/Ray.h core/Ray.cpp hittables/Hittable.h hittables/Sphere.h hittables/Sphere.cpp hittables/HittableList.h hittables/HittableList.cpp core/Common.h core/Camera.h core/Camera.cpp materials/Material.h materials/Diffuse.h materials/Diffuse.cpp materials/metal.h materials/metal.cpp materials/Glass.h materials/Glass.cpp
        core/Writer.cpp)
