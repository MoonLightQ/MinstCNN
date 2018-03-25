#pragma once
#include "layer.hpp"

class convolutional_layer : public layer {
public:
    convolutional_layer(
        layer *_forward_layer,
        int32_t _filter_num, 
        int32_t _filter_size = 3,
        int32_t _stride = 1, 
        int32_t _padding = 1
    ) : 
        layer(_forward_layer),
        filter_num(_filter_num),
        filter_size(_filter_size),
        stride(_stride),
        padding(_padding)
    {
        output_depth = _filter_num;
        
        assert((forward_layer->output_size - filter_size + 2 * padding) % stride == 0);
    }
    int32_t filter_num;
    int32_t filter_size;
    int32_t stride;
    int32_t padding;
};