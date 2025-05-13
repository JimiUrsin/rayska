#include "Metal.h"

namespace Rayska
{

Metal::Metal(const Color& a, float fuzz) : albedo_(a), fuzz_(fuzz) { if (fuzz_ > 1) fuzz_ = 1.0f; }

bool Metal::scatter(const Ray &ray_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const {
    const Vec3d reflected = reflect(ray_in.direction(), rec.normal);
    scattered = Ray(rec.p, unitVector(reflected + fuzz_ * Vec3d::randomInUnitSphere()));
    attenuation = albedo_;
    return (dot(scattered.direction(), rec.normal) > 0);
}

} // namespace Rayska
