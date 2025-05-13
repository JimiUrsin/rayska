#pragma once

#include "../hittables/Hittable.h"
#include "Material.h"

namespace Rayska
{

class Metal : public Material {
public:
    Metal(const Color& a, float fuzz);

    bool scatter(const Ray& ray_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const override;

private:
    Color albedo_;
    float fuzz_;
};

} // namespace Rayska
