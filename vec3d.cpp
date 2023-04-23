#include "vec3d.hpp"

vec3d::vec3d() : x_(0), y_(0), z_(0) {}
vec3d::vec3d(float x, float y, float z) : x_(x), y_(y), z_(z) {}

float vec3d::x() const { return x_; }
float vec3d::y() const { return y_; }
float vec3d::z() const { return z_; }

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

float vec3d::length() const {
    return std::sqrt(length_squared());
}

float vec3d::length_squared() const {
    return (x_ * x_) + (y_ * y_) + (z_ * z_);
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
