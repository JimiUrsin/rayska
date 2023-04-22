#include "vec3d.hpp"

vec3d::vec3d() : x_(0), y_(0), z_(0) {}
vec3d::vec3d(float x, float y, float z) : x_(x), y_(y), z_(z) {}

[[nodiscard]] float vec3d::x() const { return x_; }
[[nodiscard]] float vec3d::y() const { return y_; }
[[nodiscard]] float vec3d::z() const { return z_; }

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
    return *this *= 1/t;
}
