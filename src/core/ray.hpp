#ifndef RAYSKA_RAY_HPP
#define RAYSKA_RAY_HPP

#include "common.hpp"
#include "vec3d.hpp"

class ray {
public:
    ray();
    ray(const point3d& origin, const vec3d& direction);

    [[nodiscard]] point3d origin() const;
    [[nodiscard]] vec3d direction() const;

    [[nodiscard]] point3d at(float t) const;

private:
    point3d origin_;
    vec3d direction_;
};

#endif //RAYSKA_RAY_HPP
