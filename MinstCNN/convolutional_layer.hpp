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
        filter_height(_filter_size),
        filter_width(_filter_size),
        stride(_stride),
        padding(_padding)
    {
        // initialize filters
        assert((input_height - filter_height + 2 * padding) % stride == 0);
        assert((input_width - filter_width + 2 * padding) % stride == 0);
        
        filters = new filter[filter_num];
        for (int32_t index = 0; index != filter_num; index++) {
            filters[index].initialize(filter_height, filter_width, input_depth);
        }

        // initialize inputs(padding)
        assert(backward_layer != nullptr);
        assert(padding <= RESERVED_PADDING_SIZE);

        inputs.clear();
        for (int32_t index_input_depth = 0; index_input_depth < input_depth; index_input_depth++) {
            inputs.push_back(
                backward_layer
                ->raw_output_data[index_input_depth]
                ->block(
                    RESERVED_PADDING_SIZE - padding, 
                    RESERVED_PADDING_SIZE - padding,
                    input_height + 2 * padding,
                    input_width + 2 * padding
                )
            );
        }
        
        // initialize outputs
        output_height = (input_height - filter_height + 2 * padding) / stride + 1;
        output_width = (input_width - filter_width + 2 * padding) / stride + 1;
        input_height += 2 * padding;
        input_width += 2 * padding;

        outputs.clear();
        for (int32_t index_output_depth = 0; index_output_depth != output_depth; index_output_depth++) {
            raw_output_data[index_output_depth]->resize(
                output_height + 2 * RESERVED_PADDING_SIZE,
                output_width + 2 * RESERVED_PADDING_SIZE
            );
            raw_output_data[index_output_depth]->setZero();
            outputs.push_back(
                raw_output_data[index_output_depth]->block(
                    RESERVED_PADDING_SIZE,
                    RESERVED_PADDING_SIZE,
                    output_height,
                    output_width
                )
            );
        }
    }

    ~convolutional_layer() {
        delete[] filters;
    }

    void forward() {
        for (int32_t index_output_depth = 0; index_output_depth != output_depth; index_output_depth++) {
            // Binding reference
            auto& _output = outputs[index_output_depth];
            auto& _filter = filters[index_output_depth];
            // Convolution
            //std::cout << "(" << output_height << "," << output_width << ")" << std::endl;
            for (int32_t w = 0; w < output_width; w++) {
                for (int32_t h = 0; h < output_height; h++) {
                    _output(h, w) = 0;
                    for (int32_t depth = 0; depth < input_depth; depth++) {
                        
                        //std::cout << "Now Conv-ing :\n" << inputs[depth].block(h, w, filter_size, filter_size) << std::endl;
                        _output(h, w) += _filter.weights[depth].cwiseProduct(inputs[depth].block(h, w, filter_height, filter_width)).sum();
                    }
                    _output(h, w) += _filter.bias;
                    // activation func
                    _output(h, w) = relu(_output(h, w));
                }
            }
        }
        if (forward_layer != nullptr) {
            forward_layer->forward();
        }
    }

    void backward() {

    }
    int32_t filter_num;
    int32_t filter_size;
    int32_t filter_height;
    int32_t filter_width;
    int32_t stride;
    int32_t padding;
    
    filter *filters;

protected:
    void pad(int32_t _padding) {

    }
};
