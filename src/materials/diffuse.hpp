#ifndef RAYSKA_DIFFUSE_HPP
#define RAYSKA_DIFFUSE_HPP

#include "material.hpp"
#include "../hittables/hittable.hpp"


class diffuse : public material {
public:
    explicit diffuse(const color& a);
    virtual ~diffuse() = default;

    bool scatter(const ray& ray_in, const hit_record& rec, color& attenuation, ray& scattered) const override;

private:
    color albedo;
};



#endif //RAYSKA_DIFFUSE_HPP
