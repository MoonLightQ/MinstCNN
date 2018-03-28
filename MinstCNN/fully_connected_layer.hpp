#pragma once
#include "layer.hpp"

class fully_connected_layer : public layer {
public:
    fully_connected_layer(
        layer *_backward_layer,
        int32_t _neuron_num
    ) :
        layer(_backward_layer, _neuron_num)
    {
        neuron_num = _neuron_num;
        // reinitialize
        for (auto& pointer_to_matrix : raw_output_data) {
            delete pointer_to_matrix;
        }
        raw_output_data.clear();
        raw_output_data.push_back(new Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>);
        raw_output_data[0]->resize(neuron_num, 1);
        output_height = neuron_num;
        output_width = 1;
        output_depth = 1;
        outputs.clear();
        outputs.push_back(raw_output_data[0]->block(0, 0, neuron_num, 1));
        // neuron init
        neurons = new filter[neuron_num];
        for (int32_t index = 0; index != neuron_num; index++) {
            neurons[index].initialize(input_height, input_width, input_depth);
        }
    }

    ~fully_connected_layer() {
        delete[] neurons;
    }

    void forward() {
        for (int32_t index_output_depth = 0; index_output_depth != neuron_num; index_output_depth++) {
            outputs[0](index_output_depth, 0) = 0.;
            for (int32_t index_input_depth = 0; index_input_depth != input_depth; index_input_depth++) {
                outputs[0](index_output_depth, 0) += 
                    neurons[index_output_depth]
                        .weights[index_input_depth]
                        .cwiseProduct(inputs[index_input_depth])
                        .sum();
            }
            outputs[0](index_output_depth, 0) += neurons[index_output_depth].bias;
        }
        if (forward_layer != nullptr) {
            forward_layer->forward();
        }
    }

    void backward() {

    }

    int32_t neuron_num;
    filter *neurons;
};
