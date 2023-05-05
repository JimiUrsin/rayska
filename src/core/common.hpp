#ifndef RAYSKA_COMMON_HPP
#define RAYSKA_COMMON_HPP

#include <cmath>
#include <limits>
#include <memory>
#include <random>

const float inf = std::numeric_limits<float>::infinity();
const float pi = 3.14159265358979f;

inline float dtor(float degrees) {
    return degrees * pi / 180.0f;
}

inline float random_float() {
    static std::uniform_real_distribution<float> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline float random_float(float min, float max) {
    static std::uniform_real_distribution<float> distribution(min, max);
    static std::mt19937 generator;
    return distribution(generator);
}

inline float clamp(float x, float min, float max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

#endif //RAYSKA_COMMON_HPP
