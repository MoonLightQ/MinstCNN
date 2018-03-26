#pragma once
#include "layer.hpp"
#include "filter.hpp"
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
        filters = new filter(filter_size, backward_layer->output_depth);
        assert((backward_layer->output_size - filter_size + 2 * padding) % stride == 0);
        output_size = (backward_layer->output_size - filter_size + 2 * padding) / stride + 1;

        for (int32_t index_output_depth = 0; index_output_depth != output_depth; index_output_depth++) {
            outputs[index_output_depth].resize(output_size, output_size);
            filters[index_output_depth].output = &outputs[index_output_depth];
        }
        
    }

    void forward() {
        for (int32_t index_output_depth = 0; index_output_depth != output_depth; index_output_depth++) {
            // Binding reference
            auto& _output = outputs[index_output_depth];
            auto& _filter = filters[index_output_depth];
            // Inside convolution
            
            // Edge convolution (include padding)

        }
    }

    void backward() {

    }
    int32_t filter_num;
    int32_t filter_size;
    int32_t stride;
    int32_t padding;
    
    filter *filters;
};