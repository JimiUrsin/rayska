#include "Sphere.h"

namespace Rayska
{

Sphere::Sphere(Point3d center, float r, std::shared_ptr<Material> m) : center_(center), radius_(r), mat_ptr_(m) {}

bool Sphere::hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const {
    Vec3d oc = r.origin() - center_;

    float a = r.direction().lengthSquared();
    float h = dot(oc, r.direction());
    float c = dot(oc, oc) - radius_*radius_;

    float discriminant = h*h - a*c;
    if (discriminant < 0) return false;
    float sqrtd = std::sqrt(discriminant);

    float root = (-h - sqrtd) / a;

    if (root < tMin || root > tMax) {
        root = (-h + sqrtd) / a;
        if (root < tMin || root > tMax)
            return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    Vec3d outward_normal = (rec.p - center_) / radius_;
    rec.setFaceNormal(r, outward_normal);
    rec.mat_ptr = mat_ptr_;

    return true;
}

} // namespace Rayska
