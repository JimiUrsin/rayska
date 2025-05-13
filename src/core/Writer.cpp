#include "Writer.h"

#include <algorithm>
#include <cmath>
#include <ostream>

namespace Rayska
{

void writeColor(std::ostream &out, const Color &c, int samplesPerPixel)
{
    float b = c.z;

    const float scale = 1.0f / static_cast<float>(samplesPerPixel);

    const float r = std::sqrt(scale * c.x);
    const float g = std::sqrt(scale * c.y);
    b = std::sqrt(scale * b);

    out << static_cast<int>(256 * std::clamp(r, 0.0f, 0.999f)) << " "
        << static_cast<int>(256 * std::clamp(g, 0.0f, 0.999f)) << " "
        << static_cast<int>(256 * std::clamp(b, 0.0f, 0.999f)) << "\n";
}

} // namespace Rayska
