#ifndef RAYSKA_VEC3D_HPP
#define RAYSKA_VEC3D_HPP

#include <cmath>
#include <iostream>

class vec3d {
public:
    vec3d();
    vec3d(float x, float y, float z);

    [[nodiscard]] float x() const;
    [[nodiscard]] float y() const;
    [[nodiscard]] float z() const;

    vec3d& operator+=(const vec3d &v);
    vec3d& operator*=(float t);
    vec3d& operator/=(float t);

private:
    float x_, y_, z_;
};

using color = vec3d;
using point3d = vec3d;

#endif //RAYSKA_VEC3D_HPP
