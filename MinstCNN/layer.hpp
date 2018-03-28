#pragma once
#include "common.hpp"

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
            raw_output_data.push_back(new Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>);
        }
        if (backward_layer != nullptr) {
            inputs = backward_layer->outputs;
            input_depth = backward_layer->output_depth;
            input_width = backward_layer->output_width;
            input_height = backward_layer->output_height;
            backward_layer->forward_layer = this;
        }
    }

    virtual ~layer() {
        for (auto& pointer_to_matrix : raw_output_data) {
            delete pointer_to_matrix;
        }
    }

    int32_t input_depth;
    int32_t input_width;
    int32_t input_height;
    int32_t output_depth;
    int32_t output_width;
    int32_t output_height;
    std::vector<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> *> raw_output_data;
    std::vector<Eigen::DenseBase<Eigen::MatrixXd>::BlockXpr> outputs;
    std::vector<Eigen::DenseBase<Eigen::MatrixXd>::BlockXpr> inputs;

protected:
    layer *forward_layer;
    layer *backward_layer;
};
