#ifndef RAYSKA_MATERIAL_HPP
#define RAYSKA_MATERIAL_HPP

#include "../core/ray.hpp"

struct hit_record;

class material {
public:
    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const = 0;
};

#endif //RAYSKA_MATERIAL_HPP
