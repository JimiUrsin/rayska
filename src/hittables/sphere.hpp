#ifndef RAYSKA_SPHERE_HPP
#define RAYSKA_SPHERE_HPP

#include "hittable.hpp"
#include "../core/vec3d.hpp"


class sphere : public hittable {
public:
    sphere();
    sphere(point3d center, float r, std::shared_ptr<material> m);
    virtual ~sphere() = default;

    [[nodiscard]] virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const override;

public:
    point3d center;
    float radius;
    std::shared_ptr<material> mat_ptr;
};

#endif //RAYSKA_SPHERE_HPP
