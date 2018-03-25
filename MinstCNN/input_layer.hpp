#pragma once
#include "layer.hpp"

class input_layer : public layer {
public:
    input_layer(
        layer *_backward_layer,
        int32_t _size,
        int32_t _depth = 3
    ) : 
        layer(_backward_layer, _depth)
    {
        output_size = _size;
        for (int32_t index = 0; index != output_depth; index++) {
            outputs[index].resize(output_size, output_size);
        }
    }

    void forward() {

    }
    void backward() {

    }

    ~input_layer() {

    }
};
