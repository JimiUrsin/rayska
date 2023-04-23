#include "ray.hpp"

ray::ray() = default;
ray::ray(const point3d &origin, const vec3d& direction) : orig(origin), dir(direction) {}

[[nodiscard]] point3d ray::origin() const { return orig; }
[[nodiscard]] vec3d ray::direction() const { return dir; }

[[nodiscard]] point3d ray::at(float t) const {
    return orig + dir * t;
}
