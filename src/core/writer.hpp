#ifndef RAYSKA_WRITER_HPP
#define RAYSKA_WRITER_HPP

#include <iostream>

#include "vec3d.hpp"

void write_color(std::ostream &out, color c, int samples_per_pixel) {
    float r = c.x();
    float g = c.y();
    float b = c.z();

    float scale = 1.0f / samples_per_pixel;
    r = std::sqrt(scale * r);
    g = std::sqrt(scale * g);
    b = std::sqrt(scale * b);

    out << static_cast<int>(256 * clamp(r, 0, 0.999)) << " "
        << static_cast<int>(256 * clamp(g, 0, 0.999)) << " "
        << static_cast<int>(256 * clamp(b, 0, 0.999)) << "\n";
}

#endif //RAYSKA_WRITER_HPP
