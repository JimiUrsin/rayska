
#include "Camera.h"

namespace Rayska
{

Camera::Camera() : Camera(
        Point3d(0, 0, 0),
        Point3d(0, 0, 1),
        Point3d(0, 1, 0),
        90.0f,
        16.0f / 9.0f,
        2.0f,
        1) {}

Camera::Camera(const Point3d &lookFrom, const Point3d &lookAt, const Vec3d &viewUp, float verticalFov, float aspectRatio, float aperture, float focusDistance) {
    const float theta = dtor(verticalFov);
    const float h = std::tan(theta / 2.0f);
    const float viewportHeight = 2.0f * h;
    const float viewportWidth = aspectRatio * viewportHeight;

    w = unitVector(lookFrom - lookAt);
    u = unitVector(cross(viewUp, w));
    v = cross(w, u);

    origin = lookFrom;
    horizontal = focusDistance * viewportWidth * u;
    vertical = focusDistance * viewportHeight * v;
    lowerLeftCorner = origin - horizontal / 2.0f - vertical / 2.0f - focusDistance * w;

    lensRadius = aperture / 2;
}

Ray Camera::getRay(float x, float y) const {
    const Vec3d random_offset = lensRadius * Vec3d::randomInUnitCircle();
    const Vec3d origin_offset = u * random_offset.x + v * random_offset.y;
    return {origin + origin_offset,
            lowerLeftCorner + x * horizontal + y * vertical - origin - origin_offset};
}

} // namespace Rayska
