#include "Glass.h"

namespace Rayska
{
bool Glass::scatter(const Ray &ray_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const {
    attenuation = Color(1.0f, 1.0f, 1.0f);
    float refractive_ratio;

    if (rec.front_face)
        refractive_ratio = 1.0f / refractive_index_;
    else
        refractive_ratio = refractive_index_;

    const Vec3d unit_direction = unitVector(ray_in.direction());

    const float cosTheta = std::fmin(dot(-unit_direction, rec.normal), 1.0f);
    const float sinTheta = std::sqrt(1.0f - cosTheta * cosTheta);

    const bool cannotRefract = refractive_ratio * sinTheta > 1.0f;
    Vec3d direction;

    if (cannotRefract || reflectance(cosTheta, refractive_ratio) > random_float()) {
        direction = reflect(unit_direction, rec.normal);
    } else {
        direction = refract(unit_direction, rec.normal, refractive_ratio);
    }

    scattered = Ray(rec.p, direction);
    return true;
}

float Glass::reflectance(float cosine, float refractive_index) {
    // Shlick approximation
    float r_0 = (1.0f - refractive_index) / (1.0f + refractive_index);
    r_0 = r_0 * r_0;
    return r_0 + (1.0f - r_0) * std::pow((1.0f - cosine), 5.0f);
}

} // namespace Rayska
