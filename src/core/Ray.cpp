#include "Ray.h"

namespace Rayska
{

Ray::Ray() = default;
Ray::Ray(const Point3d& origin, const Vec3d& direction) : origin_(origin), direction_(direction) {}

Point3d Ray::origin() const { return origin_; }
Vec3d Ray::direction() const { return direction_; }

Point3d Ray::at(float t) const {
    return origin_ + direction_ * t;
}

} // namespace Rayska
