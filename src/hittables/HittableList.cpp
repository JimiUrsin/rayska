#include "HittableList.h"

namespace Rayska
{

HittableList::HittableList(std::shared_ptr<Hittable> object) {
    objects.push_back(object);
}

void HittableList::clear() {
    objects.clear();
}

void HittableList::add(std::shared_ptr<Hittable> object) {
    objects.push_back(object);
}

bool HittableList::hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const {
    HitRecord temp_rec;
    bool hit_anything = false;
    float closest_so_far = tMax;

    for (const auto& object : objects) {
        if (object->hit(r, tMin, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}

} // namespace Rayska