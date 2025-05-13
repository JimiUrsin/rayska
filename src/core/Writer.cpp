#include "Writer.h"

#include <algorithm>
#include <fstream>
#include <iostream>

namespace Rayska
{

void writePpm(const std::string &filename, int width, int height, const std::vector<Color> &pixels)
{
    std::ofstream outfile{filename};

    outfile << "P3\n";
    outfile << width << " " << height << "\n";
    outfile << "255\n";

    for (const auto &pixel : pixels)
    {
        outfile << static_cast<int>(256 * std::clamp(pixel.x, 0.0f, 0.999f)) << " "
                << static_cast<int>(256 * std::clamp(pixel.y, 0.0f, 0.999f)) << " "
                << static_cast<int>(256 * std::clamp(pixel.z, 0.0f, 0.999f)) << "\n";
    }
}

} // namespace Rayska
