#pragma once
#include "basic.hpp"
#include "layers.hpp"

class CNN {
public:
    CNN() {
        initialize();
    }

private:
    void initialize() {
        srand((unsigned)time(NULL));
    }

};