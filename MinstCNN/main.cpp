#include <iostream>
#include <Eigen/Dense>
#include "input_layer.hpp"

class neuron {
    Eigen::Vector2d v;
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

int main(int argc, char **argv) {
    Eigen::Matrix2d a;
    a << 1, 3, 4, 5;
    std::cout << a << std::endl;
    input_layer l(nullptr, 2);
    l.outputs[0] << 1, 2, 3, 4;
    std::cout << l.outputs[0];
    return 0;
}
