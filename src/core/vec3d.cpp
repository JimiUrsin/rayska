#include "vec3d.hpp"

vec3d::vec3d() : x_(0), y_(0), z_(0) {}
vec3d::vec3d(float x, float y, float z) : x_(x), y_(y), z_(z) {}

float vec3d::x() const { return x_; }
float vec3d::y() const { return y_; }
float vec3d::z() const { return z_; }

vec3d vec3d::operator-() const  {
    return {-x_, -y_, -z_};
}

vec3d& vec3d::operator+=(const vec3d& rhs) {
    x_ += rhs.x_;
    y_ += rhs.y_;
    z_ += rhs.z_;

    return *this;
}

vec3d& vec3d::operator*=(float t) {
    x_ *= t;
    y_ *= t;
    z_ *= t;

    return *this;
}

vec3d& vec3d::operator/=(float t) {
    x_ /= t;
    y_ /= t;
    z_ /= t;

    return *this;
}

float vec3d::length() const {
    return std::sqrt(length_squared());
}

float vec3d::length_squared() const {
    return (x_ * x_) + (y_ * y_) + (z_ * z_);
}

bool vec3d::near_zero() const {
    const float threshold = 1e-8;
    return (std::fabs(x_) < threshold) && (std::fabs(y_) < threshold) && (std::fabs(z_) < threshold);
}

vec3d vec3d::random() {
    return {random_float(), random_float(), random_float()};
}

vec3d vec3d::random(float min, float max) {
    return {random_float(min, max), random_float(min, max), random_float(min, max)};
}

vec3d vec3d::random_in_unit_sphere() {
    while (true) {
        vec3d p = random(-1, 1);
        if (p.length_squared() >= 1) continue; // Outside sphere, try again
        return p;
    }
}



vec3d vec3d::random_unit_vector() {
    return unit_vector(random_in_unit_sphere());
}

vec3d vec3d::random_in_hemisphere(const vec3d &normal) {
    vec3d in_unit_sphere = random_in_unit_sphere();
    if (dot(in_unit_sphere, normal) > 0.0)
        return in_unit_sphere;
    else
        return -in_unit_sphere;
}

vec3d vec3d::random_in_unit_circle() {
    while (true) {
        vec3d random_in_circle = vec3d(random_float(-1, 1), random_float(-1, 1), 0);
        if (random_in_circle.length_squared() >= 1) continue;
        return random_in_circle;
    }
}



vec3d operator+(const vec3d& lhs, const vec3d& rhs) {
    return {lhs.x() + rhs.x(),
            lhs.y() + rhs.y(),
            lhs.z() + rhs.z()};
}

vec3d operator-(const vec3d& lhs, const vec3d& rhs) {
    return {lhs.x() - rhs.x(),
            lhs.y() - rhs.y(),
            lhs.z() - rhs.z()};
}

vec3d operator*(const vec3d& lhs, const vec3d& rhs) {
    return {lhs.x() * rhs.x(),
            lhs.y() * rhs.y(),
            lhs.z() * rhs.z()};
}

vec3d operator*(float t, const vec3d &rhs) {
    return {t * rhs.x(),
            t * rhs.y(),
            t * rhs.z()};
}

vec3d operator*(const vec3d& lhs, float t) {
    return t * lhs;
}

vec3d operator/(vec3d lhs, float t) {
    return {lhs.x() / t,
            lhs.y() / t,
            lhs.z() / t};
}

float dot(const vec3d& lhs, const vec3d& rhs) {
    return lhs.x() * rhs.x() +
           lhs.y() * rhs.y() +
           lhs.z() * rhs.z();
}

vec3d cross(const vec3d& lhs, const vec3d& rhs) {
    return {lhs.y() * rhs.z() - lhs.z() * rhs.y(),
            lhs.z() * rhs.x() - lhs.x() * rhs.z(),
            lhs.x() * rhs.y() - lhs.y() * rhs.x()};
}

vec3d unit_vector(vec3d v) {
    return v / v.length();
}

vec3d reflect(const vec3d& ray_in, const vec3d& normal) {
    return ray_in - 2 * dot(ray_in, normal) * normal;
}

vec3d refract(const vec3d& ray_in, const vec3d& normal, float refractive_ratio) {
    float cos_theta = std::fmin(dot(-ray_in, normal), 1.0f);
    vec3d perpendicular_ray_out = refractive_ratio * (ray_in + cos_theta * normal);
    vec3d parallel_ray_out = -std::sqrt(std::fabs(1.0f - perpendicular_ray_out.length_squared())) * normal;
    return perpendicular_ray_out + parallel_ray_out;
}
