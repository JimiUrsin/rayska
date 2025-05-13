#pragma once

#include "Material.h"

namespace Rayska
{

class Diffuse : public Material {
public:
    explicit Diffuse(const Color& a);

    bool scatter(const Ray& ray_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const override;

private:
    Color albedo;
};

} // namespace Rayska
