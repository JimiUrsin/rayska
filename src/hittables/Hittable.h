#pragma once

#include <memory>

#include "../core/Ray.h"

namespace Rayska
{
class Material;

struct HitRecord {
    Point3d p;
    Vec3d normal;
    std::shared_ptr<Material> mat_ptr;
    float t;
    bool front_face;

    void setFaceNormal(const Ray& r, const Vec3d& outwardNormal) {
        front_face = dot(r.direction(), outwardNormal) < 0;
        normal = front_face ? outwardNormal : -outwardNormal;
    }
};

class Hittable {
public:
    [[nodiscard]] virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const = 0;
    virtual ~Hittable() = default;
};

} // namespace Rayska
