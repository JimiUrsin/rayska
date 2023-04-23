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

    [[nodiscard]] vec3d operator-() const;

    vec3d& operator+=(const vec3d &v);
    vec3d& operator*=(float t);
    vec3d& operator/=(float t);

    [[nodiscard]] float length() const;
    [[nodiscard]] float length_squared() const;
private:
    float x_, y_, z_;
};

[[nodiscard]] vec3d operator+(const vec3d& lhs, const vec3d& rhs);
[[nodiscard]] vec3d operator-(const vec3d& lhs, const vec3d& rhs);
[[nodiscard]] vec3d operator*(const vec3d& lhs, const vec3d& rhs);

[[nodiscard]] vec3d operator*(float t, const vec3d& v);
[[nodiscard]] vec3d operator*(const vec3d& v, float t);

[[nodiscard]] vec3d operator/(vec3d v, float t);

[[nodiscard]] float dot(const vec3d& lhs, const vec3d& rhs);
[[nodiscard]] vec3d cross(const vec3d& lhs, const vec3d& rhs);
[[nodiscard]] vec3d unit_vector(vec3d v);

using color = vec3d;
using point3d = vec3d;

#endif //RAYSKA_VEC3D_HPP
