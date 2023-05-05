#ifndef RAYSKA_HITTABLE_HPP
#define RAYSKA_HITTABLE_HPP

#include "../core/common.hpp"
#include "../core/ray.hpp"
#include "../materials/material.hpp"

struct hit_record {
    point3d p;
    vec3d normal;
    std::shared_ptr<material> mat_ptr;
    float t;
    bool front_face;

    inline void set_face_normal(const ray& r, const vec3d& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
public:
    [[nodiscard]] virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};

#endif //RAYSKA_HITTABLE_HPP
