#pragma once
#include "basic.hpp"

class layer {
public:
    virtual void forward() = 0;
    virtual void backward() = 0;
    layer(
        layer *_backward_layer, 
        int32_t _output_depth
    ) : 
        backward_layer(_backward_layer),
        output_depth(_output_depth)
    {
        outputs = new Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>[output_depth];
    }
    virtual ~layer() {
        delete[] outputs;
    }

    int32_t output_depth;
    int32_t output_size;
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> *outputs;
protected:
    layer *forward_layer;
    layer *backward_layer;
};