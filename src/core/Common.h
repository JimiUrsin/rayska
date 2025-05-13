#pragma once

#include <limits>
#include <random>

namespace Rayska
{

constexpr float inf = std::numeric_limits<float>::infinity();
constexpr float pi = 3.14159265358979f;

inline float dtor(float degrees) {
    return degrees * pi / 180.0f;
}

static std::random_device rd{};
static std::mt19937 generator{rd()};
static std::uniform_real_distribution distribution{0.0f, 1.0f};

inline float random_float() {
    return distribution(generator);
}

inline float random_float(float min, float max) {
    std::uniform_real_distribution clampedDistribution{min, max};
    return clampedDistribution(generator);
}

} // namespace Rayska
