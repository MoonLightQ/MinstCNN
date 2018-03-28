#pragma once
#include "layer.hpp"

class input_layer : public layer {
public:
    input_layer(
        int32_t _height, 
        int32_t _width, 
        int32_t _depth = 3
    ) : 
        layer(nullptr, _depth)
    {
        output_width = _width;
        output_height = _height;
        for (int32_t index = 0; index != output_depth; index++) {
            raw_output_data[index]->resize(
                output_height + 2 * RESERVED_PADDING_SIZE, 
                output_width + 2 * RESERVED_PADDING_SIZE
            );
            raw_output_data[index]->setZero();
            outputs.push_back(
                raw_output_data[index]->block(
                    RESERVED_PADDING_SIZE,
                    RESERVED_PADDING_SIZE, 
                    output_height,
                    output_width
                )
            );
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
};
