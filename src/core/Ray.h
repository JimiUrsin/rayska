#pragma once

#include "Vec3d.h"

namespace Rayska
{

class Ray {
public:
    Ray();
    Ray(const Point3d& origin, const Vec3d& direction);

    [[nodiscard]] Point3d origin() const;
    [[nodiscard]] Vec3d direction() const;

    [[nodiscard]] Point3d at(float t) const;

private:
    Point3d origin_;
    Vec3d direction_;
};

} // namespace Rayska
