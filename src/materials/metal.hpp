#ifndef RAYSKA_METAL_HPP
#define RAYSKA_METAL_HPP

#include "material.hpp"
#include "../hittables/hittable.hpp"



class metal : public material {
public:
    metal(const color& a, float fuzz);
    virtual ~metal() = default;

    bool scatter(const ray& ray_in, const hit_record& rec, color& attenuation, ray& scattered) const override;

private:
    color albedo_;
    float fuzz_;
};


#endif //RAYSKA_METAL_HPP
