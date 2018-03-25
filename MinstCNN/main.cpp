#include <iostream>
#include <Eigen/Dense>

class neuron {
    Eigen::Vector2d v;
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

int main(int argc, char **argv) {
    Eigen::Matrix2d a;
    a << 1, 3, 4, 5;
    std::cout << a << std::endl;
    return 0;
}
