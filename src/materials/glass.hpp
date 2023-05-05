#ifndef RAYSKA_GLASS_HPP
#define RAYSKA_GLASS_HPP

#include "../core/common.hpp"
#include "../hittables/hittable.hpp"
#include "material.hpp"
#include "../core/vec3d.hpp"


class glass : public material {
public:
    glass(float refractive_index) : refractive_index_(refractive_index) {}
    bool scatter(const ray& ray_in, const hit_record& rec, color& attenuation, ray& scattered) const override;
    virtual ~glass() = default;

private:
    float refractive_index_;
    static float reflectance(float cosine, float refractive_index);
};

#endif //RAYSKA_GLASS_HPP
