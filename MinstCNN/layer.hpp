#pragma once
#include "basic.hpp"

class layer {
public:
    virtual void forward() = 0;
    virtual void backward() = 0;
    layer(
        layer *_backward_layer, 
        int32_t _output_depth
    ) : 
        backward_layer(_backward_layer),
        output_depth(_output_depth)
    {
        for (int index = 0; index < output_depth; index++) {
            raw.push_back(new Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>);
        }
//        raw = new Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>[output_depth];
        outputs = raw;
        if (backward_layer != nullptr) {
            inputs = backward_layer->outputs;
            input_depth = backward_layer->output_depth;
            input_size = backward_layer->output_size;
            backward_layer->forward_layer = this;
        }
    }

    virtual ~layer() {
        for (auto& pointer_to_matrix : raw) {
            delete pointer_to_matrix;
        }
    }

    int32_t input_depth;
    int32_t input_size;
    int32_t output_depth;
    int32_t output_size;
    std::vector<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> *> raw;
    std::vector<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> *> outputs;
    std::vector<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> *> inputs;

protected:
    layer *forward_layer;
    layer *backward_layer;
};