
#include "diffuse.hpp"

diffuse::diffuse(const color& a) : albedo(a) {}

bool diffuse::scatter([[maybe_unused]] const ray& ray_in, const hit_record& rec, color& attenuation, ray& scattered) const {
    vec3d scatter_direction = unit_vector(rec.normal + vec3d::random_in_unit_sphere());

    if (scatter_direction.near_zero())
        scatter_direction = rec.normal;

    scattered = ray(rec.p, scatter_direction);
    attenuation = albedo;
    return true;
}
