#include <fstream>

#include "ray.hpp"
#include "vec3d.hpp"
#include "writer.hpp"

float hit_sphere(const point3d& center, float radius, const ray& r) {
    vec3d oc = r.origin() - center;

    float a = dot(r.direction(), r.direction());
    float h = dot(oc, r.direction());
    float c = dot(oc, oc) - radius*radius;

    float discriminant = h*h - a*c;

    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-h - std::sqrt(discriminant)) / a;
    }
}

color ray_color(const ray& r) {
    float t = hit_sphere(point3d(0,0,-1), 0.5, r);

    if (t > 0.0) {
        vec3d normal = unit_vector(r.at(t) - vec3d(0, 0, -1));
        return 0.5*color(normal.x() + 1, normal.y() + 1, normal.z() + 1);
    }

    vec3d unit_direction = unit_vector(r.direction());
    t = 0.5f * (unit_direction.y() + 1.0f);
    return (1.0f - t) * color(1.0, 1.0, 1.0) + t * color(0.7, 0.5, 1.0);
}

int main() {
    const float aspect_ratio = 16.0 / 9.0;
    const int img_width = 400;
    const int img_height = static_cast<int>(img_width / aspect_ratio);

    const std::string FILENAME = "out.ppm";

    float viewport_height = 2.0;
    float viewport_width = aspect_ratio * viewport_height;
    float focal_length = 1.0;

    auto origin = point3d(0, 0, 0);
    auto horizontal = vec3d(viewport_width, 0, 0);
    auto vertical = vec3d(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3d(0, 0, focal_length);

    std::ofstream outfile(FILENAME);

    outfile << "P3\n";
    outfile << img_width << " " << img_height << "\n";
    outfile << "255\n";

    for (int y = 0; y < img_height; ++y) {
        for (int x = 0; x < img_width; ++x) {
            auto u = float(x) / (img_width - 1);
            auto v = float(y) / (img_height - 1);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            color pixel_color = ray_color(r);

            write_color(outfile, pixel_color);
        }
    }
}
