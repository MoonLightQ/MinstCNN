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
        int32_t _padding = 0
    ) : 
        layer(_backward_layer, _filter_num),    // The output depth is the same as the number of filters. 
        filter_num(_filter_num),
        filter_size(_filter_size),
        stride(_stride),
        padding(_padding)
    {
        assert((input_size - filter_size + 2 * padding) % stride == 0);
        filters = new filter[filter_num];
        for (int32_t index = 0; index != filter_num; index++) {
            filters[index].initialize(filter_size, input_depth);
        }
        output_size = (input_size - filter_size + 2 * padding) / stride + 1;

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
            for (int32_t x = 0; x < output_size; x++) {
                for (int32_t y = 0; y < output_size; y++) {
                    _output(y, x) = 0;
                    for (int32_t depth = 0; depth < input_depth; depth++) {
                        _output(y, x) += _filter.weights[depth].cwiseProduct(inputs[depth].block(y, x, filter_size, filter_size)).sum();
                    }
                }
            }
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