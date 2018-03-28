#pragma once
#include "layer.hpp"

class softmax_layer : public layer {
public:
    softmax_layer(layer *_backward_layer) :
        layer(_backward_layer, 1) {

        assert(input_width == 1);
        
        output_height = input_height;
        output_width = 1;
        output_depth = 1;
        output_size = output_height;
        input_size = input_height;
        raw_output_data[0]->resize(input_height, 1);
        outputs.clear();
        outputs.push_back(raw_output_data[0]->block(0, 0, input_height, 1));
    }
    void forward() {
        double sum_exp = 0.;
        for (int32_t index = 0; index < output_height; index++) {
            outputs[0](index, 0) = exp(inputs[0](index, 0));
            sum_exp += outputs[0](index, 0);
        }
        for (int32_t index = 0; index < output_height; index++) {
            outputs[0](index, 0) /= sum_exp;
        }
        if (forward_layer != nullptr) {
            forward_layer->forward();
        }
    }

    void backward() {

    }

    int32_t input_size;
    int32_t output_size;
};
