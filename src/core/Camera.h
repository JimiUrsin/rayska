#pragma once

#include "Common.h"
#include "Ray.h"
#include "Vec3d.h"

namespace Rayska
{

class Camera {
public:
    Camera();
    Camera(const Point3d &lookFrom, const Point3d &lookAt, const Vec3d &viewUp, float verticalFov, float aspectRatio, float aperture, float focusDistance);

    [[nodiscard]] Ray getRay(float x, float y) const;

private:
    Point3d origin;
    Point3d lowerLeftCorner;

    Vec3d horizontal;
    Vec3d vertical;
    Vec3d w, u, v;

    float lensRadius;
};

} // namespace Rayska