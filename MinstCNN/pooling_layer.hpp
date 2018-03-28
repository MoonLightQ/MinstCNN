#pragma once
#include "layer.hpp"

class pooling_layer : public layer {
public:
    pooling_layer(
        layer *_backward_layer,
        int32_t _stride = 2
    ) :
        layer(_backward_layer,
            _backward_layer->output_depth
        ) 
    {
        assert(
            backward_layer != nullptr 
            && _stride > 0 
            && input_height % _stride == 0
            && input_width % _stride == 0
        );
        stride = _stride;

        output_height = input_height / stride;
        output_width = input_width / stride;
        
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
    }

    void forward() {
        for (int32_t index_output_depth = 0; index_output_depth != output_depth; index_output_depth++) {
            for (int32_t w = 0; w < output_width; w++) {
                for (int32_t h = 0; h < output_height; h++) {
                    outputs[index_output_depth](h, w)
                        = inputs[index_output_depth].block(h * stride, w * stride, stride, stride).maxCoeff();
                }
            }
        }
        if (forward_layer != nullptr) {
            forward_layer->forward();
        }
    }

    void backward() {

    }

    int32_t stride;
};
