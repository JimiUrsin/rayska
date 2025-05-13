#pragma once

#include "Hittable.h"

#include <memory>
#include <vector>

namespace Rayska
{

class HittableList : public Hittable {
public:
    HittableList() = default;
    explicit HittableList(const std::shared_ptr<Hittable> &object);

    void clear();
    void add(const std::shared_ptr<Hittable> &object);

    bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const override;

private:
    std::vector<std::shared_ptr<Hittable>> objects;
};

} // namespace Rayska