

#include "sphere.hpp"

sphere::sphere(point3d center, float r, std::shared_ptr<material> m) : center(center), radius(r), mat_ptr(m) {}

bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
    vec3d oc = r.origin() - center;

    float a = r.direction().length_squared();
    float h = dot(oc, r.direction());
    float c = oc.length_squared() - radius*radius;

    float discriminant = h*h - a*c;
    if (discriminant < 0) return false;
    float sqrtd = std::sqrt(discriminant);

    float root = (-h - sqrtd) / a;

    if (root < t_min || root > t_max) {
        root = (-h + sqrtd) / a;
        if (root < t_min || root > t_max)
            return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    vec3d outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.mat_ptr = mat_ptr;

    return true;
}
