#ifndef RAYSKA_VEC3D_HPP
#define RAYSKA_VEC3D_HPP

#include "common.hpp"

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

    [[nodiscard]] bool near_zero() const;

    [[nodiscard]] static vec3d random();
    [[nodiscard]] static vec3d random(float min, float max);

    [[nodiscard]] static vec3d random_in_unit_sphere();
    [[nodiscard]] static vec3d random_unit_vector();

    [[nodiscard]] static vec3d random_in_hemisphere(const vec3d& normal);
    [[nodiscard]] static vec3d random_in_unit_circle();

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
[[nodiscard]] vec3d reflect(const vec3d& ray_in, const vec3d& normal);
[[nodiscard]] vec3d refract(const vec3d& ray_in, const vec3d& normal, float refractive_ratio);

using color = vec3d;
using point3d = vec3d;

#endif //RAYSKA_VEC3D_HPP
