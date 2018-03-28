#pragma once
#include "common.hpp"

class filter {
public:
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> *weights;
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> *output;
    double bias;
    int32_t size;
    int32_t height;
    int32_t width;
    int32_t depth;

    filter() {

    }

    void initialize(
        int32_t _size,
        int32_t _depth
    ) {
        size = _size;
        height = _size;
        width = _size;
        depth = _depth;
        weights = new Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>[depth];
        for (int32_t index = 0; index != depth; index++) {
            weights[index].resize(height, width);
            weights[index].setRandom();
        }
    }

    void initialize(
        int32_t _height,
        int32_t _width,
        int32_t _depth
    ) {
        size = -1;
        height = _height;
        width = _width;
        depth = _depth;
        weights = new Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>[depth];
        for (int32_t index = 0; index != depth; index++) {
            weights[index].resize(height, width);
            weights[index].setRandom();
        }
        bias = 0.;
    }

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

    filter(
        int32_t _size,
        int32_t _depth,
        Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> *_output
    ) :
        filter(_size, _depth)
    {
        output = _output;
        weights = new Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>[depth];
        for (int32_t index = 0; index != depth; index++) {
            weights[index].resize(size, size);
        }

    }

    ~filter() {
        delete[] weights;
    }
};
