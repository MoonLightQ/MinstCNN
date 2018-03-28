#pragma once
#include "layer.hpp"

class input_layer : public layer {
public:
    input_layer(
        int32_t _size,
        int32_t _depth = 3
    ) : 
        layer(nullptr, _depth)
    {
        output_size = _size;
        for (int32_t index = 0; index != output_depth; index++) {
            outputs[index]->resize(output_size, output_size);
            outputs[index]->setZero();
        }
        inputs = outputs;
    }

    void forward() {
        assert(forward_layer != nullptr);
        forward_layer->forward();
    }
    void backward() {

    }

    ~input_layer() {

    }

    void pad(int32_t _padding) {

    }
};
