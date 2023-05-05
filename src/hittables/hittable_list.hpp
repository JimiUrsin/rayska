#ifndef RAYSKA_HITTABLE_LIST_HPP
#define RAYSKA_HITTABLE_LIST_HPP

#include "hittable.hpp"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable {
public:
    hittable_list() = default;
    explicit hittable_list(shared_ptr<hittable> object);

    void clear();
    void add(shared_ptr<hittable> object);

    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const override;

private:
    std::vector<shared_ptr<hittable>> objects;
};

#endif //RAYSKA_HITTABLE_LIST_HPP
