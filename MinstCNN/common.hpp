#pragma once
#include <cmath>
#include <cctype>
#include <cstdint>
#include <cassert>
#include <ctime>
#include <vector>
#include <Eigen/Dense>
#include <opencv/cv.hpp>

#define RESERVED_PADDING_SIZE 3

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

inline double gauss_rand() {

}

inline void norm_init(Eigen::MatrixXd& matrix) {
    double u1, u2;
    for (int col = 0; col < matrix.cols(); col++) {
        for (int row = 0; row < matrix.rows(); row++) {

        }
    }
}
