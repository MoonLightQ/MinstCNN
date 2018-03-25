#pragma once
#include "layer.hpp"

class convolutional_layer : public layer {
public:
    convolutional_layer(
        layer *_backward_layer,
        int32_t _filter_num, 
        int32_t _filter_size = 3,
        int32_t _stride = 1, 
        int32_t _padding = 1
    ) : 
        layer(_backward_layer, _filter_num),    // The output depth is the same as the number of filters. 
        filter_num(_filter_num),
        filter_size(_filter_size),
        stride(_stride),
        padding(_padding)
    {
        assert((backward_layer->output_size - filter_size + 2 * padding) % stride == 0);
        output_size = (backward_layer->output_size - filter_size + 2 * padding) / stride + 1;
        for (int32_t index = 0; index != output_depth; index++) {
            outputs[index].resize(output_size, output_size);
        }
    }
    int32_t filter_num;
    int32_t filter_size;
    int32_t stride;
    int32_t padding;
};