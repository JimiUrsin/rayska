
#include "metal.hpp"

metal::metal(const color& a, float fuzz) : albedo_(a), fuzz_(fuzz) { if (fuzz_ > 1) fuzz_ = 1.0f; }

bool metal::scatter(const ray &ray_in, const hit_record& rec, color& attenuation, ray& scattered) const {
    vec3d reflected = reflect(unit_vector(ray_in.direction()), rec.normal);
    scattered = ray(rec.p, reflected + (fuzz_ * vec3d::random_in_unit_sphere()));
    attenuation = albedo_;
    return (dot(scattered.direction(), rec.normal) > 0.0f);
}
