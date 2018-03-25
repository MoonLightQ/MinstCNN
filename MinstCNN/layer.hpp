#pragma once
#include "basic.hpp"

class layer {
public:
    virtual void forward() = 0;
    virtual void backward() = 0;
    layer(layer *_forward_layer) : forward_layer(_forward_layer) {

    }
    virtual ~layer() {

    }

    int32_t output_depth;
    int32_t output_size;
protected:
    layer *forward_layer;
    layer *backward_layer;
};