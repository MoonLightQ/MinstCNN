#pragma once
#include "basic.hpp"

class layer {
public:
    virtual void forward() = 0;
    virtual void backward() = 0;
    layer() {

    }
    virtual ~layer() {

    }
};