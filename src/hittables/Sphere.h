#pragma once

#include "Hittable.h"
#include "../core/Vec3d.h"

namespace Rayska
{

class Sphere : public Hittable {
public:
    Sphere(Point3d center, float r, std::shared_ptr<Material> m);

    [[nodiscard]] bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const override;

private:
    Point3d center_;
    float radius_;
    std::shared_ptr<Material> mat_ptr_;
};

} // namespace Rayska
