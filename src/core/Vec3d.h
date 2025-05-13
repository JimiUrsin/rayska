#pragma once

#include "Common.h"

namespace Rayska
{
    class Vec3d {
    public:
        Vec3d();
        Vec3d(float x, float y, float z);

        [[nodiscard]] Vec3d operator-() const;

        Vec3d& operator+=(const Vec3d& v);
        Vec3d& operator*=(const Vec3d& t);
        Vec3d& operator*=(float t);
        Vec3d& operator/=(float t);

        [[nodiscard]] float length() const;
        [[nodiscard]] float lengthSquared() const;

        [[nodiscard]] bool nearZero() const;

        [[nodiscard]] static Vec3d random();
        [[nodiscard]] static Vec3d random(float min, float max);

        [[nodiscard]] static Vec3d randomInUnitSphere();
        [[nodiscard]] static Vec3d randomUnitVector();

        [[nodiscard]] static Vec3d randomInHemisphere(const Vec3d& normal);
        [[nodiscard]] static Vec3d randomInUnitCircle();

        float x, y, z;
    };

    [[nodiscard]] Vec3d operator+(const Vec3d& lhs, const Vec3d& rhs);
    [[nodiscard]] Vec3d operator-(const Vec3d& lhs, const Vec3d& rhs);
    [[nodiscard]] Vec3d operator*(const Vec3d& lhs, const Vec3d& rhs);

    [[nodiscard]] Vec3d operator*(float t, const Vec3d& v);
    [[nodiscard]] Vec3d operator*(const Vec3d &v, float t);

    [[nodiscard]] Vec3d operator/(const Vec3d &v, float t);

    [[nodiscard]] float dot(const Vec3d& lhs, const Vec3d& rhs);
    [[nodiscard]] Vec3d cross(const Vec3d& lhs, const Vec3d& rhs);
    [[nodiscard]] Vec3d unitVector(const Vec3d &v);
    [[nodiscard]] Vec3d reflect(const Vec3d& rayIn, const Vec3d& normal);
    [[nodiscard]] Vec3d refract(const Vec3d& rayIn, const Vec3d& normal, float refractiveRatio);

    using Color = Vec3d;
    using Point3d = Vec3d;

} // namespace Rayska
