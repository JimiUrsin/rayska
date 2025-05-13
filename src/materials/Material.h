#pragma once

#include "../core/Ray.h"
#include "../hittables/Hittable.h"

namespace Rayska
{

class Material {
public:
    virtual bool scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const = 0;
    virtual ~Material() = default;
};

} // namespace Rayska

