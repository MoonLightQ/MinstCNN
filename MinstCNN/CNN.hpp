#pragma once
#include "common.hpp"
#include "layers.hpp"

class CNN {
public:
    CNN() {
        initialize();
    }

    ~CNN() {

    }

    void train(int32_t _batch_size, int32_t _epoch, double _learning_rate, double _momentum) {
        input_layer->forward();
        loss_layer->backward();
    }

    int predict() {
        return 0;
    }

private:
    void initialize() {
        srand((unsigned)time(NULL));
    }

    layer *input_layer;
    layer *output_layer;
    layer *loss_layer;

};
