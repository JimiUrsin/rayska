#pragma once

#include "Vec3d.h"

namespace Rayska
{

void writePpm(const std::string &filename, int width, int height, const std::vector<Color> &pixels);

} // namespace Rayska
