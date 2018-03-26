#include <iostream>
#include <Eigen/Dense>
#include "input_layer.hpp"

class neuron {
    Eigen::Vector2d v;
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

int main(int argc, char **argv) {
    input_layer l(nullptr, 2);
    l.outputs[1] << 1, 2, 3, 4;
    std::cout << l.outputs[1];
    return 0;
}
