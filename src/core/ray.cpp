#include "ray.hpp"

ray::ray() = default;
ray::ray(const point3d& origin, const vec3d& direction) : origin_(origin), direction_(direction) {}

point3d ray::origin() const { return origin_; }
vec3d ray::direction() const { return direction_; }

point3d ray::at(float t) const {
    return origin_ + direction_ * t;
}
