#pragma once
#include "basic.hpp"

struct filter {
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> *weights;
    int32_t size;
    int32_t depth;
    filter(
        int32_t _size,
        int32_t _depth
    ) : 
        size(_size),
        depth(_depth) 
    {
        weights = new Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>[depth];
        for (int32_t index = 0; index != depth; index++) {
            weights[index].resize(size, size);
        }
    }
};
