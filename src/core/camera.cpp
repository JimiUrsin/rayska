
#include "camera.hpp"

camera::camera() : camera(
        point3d(0, 0, 0),
        point3d(0, 0, 1),
        point3d(0, 1, 0),
        90.0f,
        16.0f / 9.0f,
        2.0f,
        1) {}

camera::camera(point3d look_from, point3d look_at, vec3d view_up, float vertical_fov, float aspect_ratio, float aperture, float focus_distance) {
    float theta = dtor(vertical_fov);
    float h = std::tan(theta / 2.0f);
    float viewport_height = 2.0f * h;
    float viewport_width = aspect_ratio * viewport_height;

    w = unit_vector(look_from - look_at);
    u = unit_vector(cross(view_up, w));
    v = cross(w, u);

    origin = look_from;
    horizontal = focus_distance * viewport_width * u;
    vertical = focus_distance * viewport_height * v;
    lower_left_corner = origin - horizontal / 2 - vertical / 2 - focus_distance * w;

    lens_radius = aperture / 2;
}

[[nodiscard]] ray camera::get_ray(float x, float y) const {
    vec3d random_offset = lens_radius * vec3d::random_in_unit_circle();
    vec3d origin_offset = u * random_offset.x() + v * random_offset.y();
    return {origin + origin_offset,
            lower_left_corner + x * horizontal + y * vertical - origin - origin_offset};
}
