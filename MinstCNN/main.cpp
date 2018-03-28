#include <iostream>
#include "CNN.hpp"

int main(int argc, char **argv) {
    CNN n;
    input_layer input(8, 8, 1);
    convolutional_layer conv(&input, 1);
    pooling_layer pooling(&conv, 2);
    fully_connected_layer fc(&pooling, 10);
    input.inputs[0] <<
        1, 2, 3, 4, 5, 6, 7, 8,
        3, 3, 4, 5, 6, 7, 1, 2,
        3, 4, 5, 6, 7, 1, 2, 3,
        4, 5, 6, 7, 1, 2, 3, 4,
        5, 6, 7, 1, 2, 3, 4, 5,
        6, 7, 1, 2, 3, 4, 5, 6,
        7, 1, 2, 3, 4, 5, 6, 6,
        7, 1, 2, 3, 4, 5, 6, 6;
    input.forward();
    std::cout << input.outputs[0] << std::endl;
    std::cout << conv.outputs[0] << std::endl;
    std::cout << pooling.outputs[0] << std::endl;
    std::cout << fc.outputs[0] << std::endl;
    return 0;
}
