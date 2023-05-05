#ifndef RAYSKA_CAMERA_HPP
#define RAYSKA_CAMERA_HPP

#include "common.hpp"
#include "ray.hpp"
#include "vec3d.hpp"


class camera {
public:
    camera();
    camera(point3d look_from, point3d look_at, vec3d view_up, float vertical_fov, float aspect_ratio, float aperture, float focus_distance);

    [[nodiscard]] ray get_ray(float x, float y) const;

private:
    point3d origin;
    point3d lower_left_corner;

    vec3d horizontal;
    vec3d vertical;
    vec3d w, u, v;

    float lens_radius;
};

#endif //RAYSKA_CAMERA_HPP
