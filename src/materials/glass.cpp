
#include "glass.hpp"

bool glass::scatter(const ray &ray_in, const hit_record &rec, color &attenuation, ray &scattered) const {
    attenuation = color(1.0f, 1.0f, 1.0f);
    float refractive_ratio;

    if (rec.front_face) {
        refractive_ratio = 1.0f / refractive_index_;
    } else {
        refractive_ratio = refractive_index_;
    }

    vec3d unit_direction = unit_vector(ray_in.direction());

    float cos_theta = std::fmin(dot(-unit_direction, rec.normal), 1.0f);
    float sin_theta = std::sqrt(1.0f - cos_theta * cos_theta);

    bool cannot_refract = refractive_ratio * sin_theta > 1.0f;
    vec3d direction;

    if (cannot_refract || reflectance(cos_theta, refractive_ratio) > random_float()) {
        direction = reflect(unit_direction, rec.normal);
    } else {
        direction = refract(unit_direction, rec.normal, refractive_ratio);
    }

    scattered = ray(rec.p, direction);
    return true;
}

float glass::reflectance(float cosine, float refractive_index) {
    // Shlick approximation
    float r_0 = (1.0f - refractive_index) / (1.0f + refractive_index);
    r_0 = r_0 * r_0;
    return r_0 + (1.0f - r_0) * std::pow((1.0f - cosine), 5.0f);
}
