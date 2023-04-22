#ifndef RAYSKA_WRITER_HPP
#define RAYSKA_WRITER_HPP

#include <iostream>

#include "vec3d.hpp"

void write_color(std::ostream &out, color c) {
    out << lroundf(256 * c.x()) << " "
        << lroundf(256 * c.y()) << " "
        << lroundf(256 * c.z()) << "\n";
}

#endif //RAYSKA_WRITER_HPP
