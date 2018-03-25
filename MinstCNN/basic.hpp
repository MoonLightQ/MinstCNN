#pragma once
#include <cmath>
#include <cctype>
#include <cstdint>
#include <cassert>

inline float sigmoid(float x) {
    return 1. / (1. + expf(-x));
}

inline float d_sigmoid(float x) {
    return sigmoid(x) * (1. - sigmoid(x));
}

inline float relu(float x) {
    return fmaxf(0., x);
}

inline float d_relu(float x) {
    return (x > 0.) ? 1. : 0.;
}

auto f = []() {};