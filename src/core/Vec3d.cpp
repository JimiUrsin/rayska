#include "Vec3d.h"

namespace Rayska
{

Vec3d::Vec3d() : x(0), y(0), z(0) {}
Vec3d::Vec3d(float x, float y, float z) : x(x), y(y), z(z) {}

Vec3d Vec3d::operator-() const {
    return {-x, -y, -z};
}

Vec3d& Vec3d::operator+=(const Vec3d& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;

    return *this;
}

Vec3d& Vec3d::operator*=(float t) {
    x *= t;
    y *= t;
    z *= t;

    return *this;
}

Vec3d& Vec3d::operator*=(const Vec3d& t) {
    x *= t.x;
    y *= t.y;
    z *= t.z;

    return *this;
}

Vec3d& Vec3d::operator/=(float t) {
    x /= t;
    y /= t;
    z /= t;

    return *this;
}

float Vec3d::length() const {
    return std::sqrt(lengthSquared());
}

float Vec3d::lengthSquared() const {
    return (x * x) + (y * y) + (z * z);
}

bool Vec3d::nearZero() const {
    constexpr float threshold = 1e-8;
    return ((std::fabs(x) < threshold) && (std::fabs(y) < threshold) && (std::fabs(z) < threshold));
}

Vec3d Vec3d::random() {
    return {random_float(), random_float(), random_float()};
}

Vec3d Vec3d::random(float min, float max) {
    return {random_float(min, max), random_float(min, max), random_float(min, max)};
}

Vec3d Vec3d::randomInUnitSphere() {
    while (true) {
        Vec3d random_vec = random(-1, 1);
        if (random_vec.lengthSquared() >= 1)
            continue; // Outside sphere, try again
        return random_vec;
    }
}

Vec3d Vec3d::randomUnitVector() {
    return unitVector(randomInUnitSphere());
}

Vec3d Vec3d::randomInHemisphere(const Vec3d &normal) {
    const Vec3d in_unit_sphere = randomInUnitSphere();
    if (dot(in_unit_sphere, normal) > 0.0)
        return in_unit_sphere;

    return -in_unit_sphere;
}

Vec3d Vec3d::randomInUnitCircle() {
    while (true) {
        Vec3d random_in_circle{
            random_float(-1, 1),
            random_float(-1, 1),
            0
        };

        if (random_in_circle.lengthSquared() >= 1) continue;
        return random_in_circle;
    }
}

Vec3d operator+(const Vec3d& lhs, const Vec3d& rhs) {
    return {lhs.x + rhs.x,
            lhs.y + rhs.y,
            lhs.z + rhs.z};
}

Vec3d operator-(const Vec3d& lhs, const Vec3d& rhs) {
    return {lhs.x - rhs.x,
            lhs.y - rhs.y,
            lhs.z - rhs.z};
}

Vec3d operator*(const Vec3d& lhs, const Vec3d& rhs) {
    return {lhs.x * rhs.x,
            lhs.y * rhs.y,
            lhs.z * rhs.z};
}

Vec3d operator*(float t, const Vec3d &v) {
    return {t * v.x,
            t * v.y,
            t * v.z};
}

Vec3d operator*(const Vec3d& v, float t) {
    return t * v;
}

Vec3d operator/(const Vec3d &v, float t) {
    return {v.x / t,
            v.y / t,
            v.z / t};
}

float dot(const Vec3d& lhs, const Vec3d& rhs) {
    return lhs.x * rhs.x +
           lhs.y * rhs.y +
           lhs.z * rhs.z;
}

Vec3d cross(const Vec3d& lhs, const Vec3d& rhs) {
    return {lhs.y * rhs.z - lhs.z * rhs.y,
            lhs.z * rhs.x - lhs.x * rhs.z,
            lhs.x * rhs.y - lhs.y * rhs.x};
}

Vec3d unitVector(const Vec3d &v) {
    return v / v.length();
}

Vec3d reflect(const Vec3d& rayIn, const Vec3d& normal) {
    return rayIn - 2 * dot(rayIn, normal) * normal;
}

Vec3d refract(const Vec3d& rayIn, const Vec3d& normal, float refractiveRatio) {
    const float cosTheta = std::fmin(dot(-rayIn, normal), 1.0f);
    const Vec3d perpendicularRayOut = refractiveRatio * (rayIn + cosTheta * normal);
    const Vec3d parallel_ray_out = -std::sqrt(std::fabs(1.0f - perpendicularRayOut.lengthSquared())) * normal;
    return perpendicularRayOut + parallel_ray_out;
}

} // namespace Rayska
