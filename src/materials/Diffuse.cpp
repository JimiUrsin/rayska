#include "Diffuse.h"

namespace Rayska
{
Diffuse::Diffuse(const Color& a) : albedo(a) {}

bool Diffuse::scatter([[maybe_unused]] const Ray& ray_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const {
    Vec3d scatter_direction = rec.normal + Vec3d::randomInUnitSphere();

    if (scatter_direction.nearZero())
        scatter_direction = rec.normal;

    scattered = Ray(rec.p, unitVector(scatter_direction));
    attenuation = albedo;
    return true;
}

} // namespace Rayska
