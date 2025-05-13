#pragma once

#include "Material.h"

namespace Rayska
{

class Glass : public Material {
public:
    explicit Glass(float refractive_index) : refractive_index_(refractive_index) {}
    bool scatter(const Ray& ray_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const override;

private:
    float refractive_index_;
    static float reflectance(float cosine, float refractive_index);
};

} // namespace Rayska
