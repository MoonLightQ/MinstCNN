#pragma once
#include <cmath>
#include <cctype>
#include <cstdint>
#include <cassert>
#include <ctime>
#include <Eigen/Dense>
#include <opencv/cv.hpp>
inline double sigmoid(double x) {
    return 1. / (1. + exp(-x));
}

inline double d_sigmoid(double x) {
    return sigmoid(x) * (1. - sigmoid(x));
}

inline double relu(double x) {
    return fmax(0., x);
}

inline double d_relu(double x) {
    return (x > 0.) ? 1. : 0.;
}
