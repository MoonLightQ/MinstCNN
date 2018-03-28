#include <iostream>
#include "CNN.hpp"

int main(int argc, char **argv) {
    input_layer input(7, 1);
    *input.inputs[0] << 
        1, 2, 3, 1, 2, 3, 1,
        2, 4, 4, 2, 1, 1, 3,
        5, 6, 3, 3 ,5, 2, 1,
        1, 2, 3, 1, 2, 3, 1,
        2, 4, 4, 2, 1, 1, 3,
        5, 6, 3, 3, 5, 2, 1,
        4, 2, 2, 4, 5, 1, 1; 
    std::cout << *input.outputs[0];
    convolutional_layer conv(&input, 1);
    input.forward();
    std::cout << conv.outputs[0];
    return 0;
}
