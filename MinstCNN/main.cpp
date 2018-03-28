#include <iostream>
#include "CNN.hpp"

int main(int argc, char **argv) {
    input_layer input(7, 7, 1);
    input.inputs[0] << 
        1, 2, 3, 4, 5, 6, 7,
        3, 3, 4, 5, 6, 7, 1,
        3, 4, 5, 6 ,7, 1, 2,
        4, 5, 6, 7, 1, 2, 3,
        5, 6, 7, 1, 2, 3, 4,
        6, 7, 1, 2, 3, 4, 5,
        7, 1, 2, 3, 4, 5, 6; 
    std::vector<Eigen::Block<Eigen::MatrixXd>::BlockXpr> refs;
    refs.push_back(input.inputs[0].block(0, 0, 2, 2));
    std::vector<Eigen::Block<Eigen::MatrixXd>::BlockXpr> refs2;
    refs2.push_back(input.inputs[0].block(1, 1, 2, 2));
    refs.clear();
    refs = refs2;
    //Eigen::DenseBase<Eigen::MatrixXd>::BlockXpr ref = input.inputs[0]->block(0, 0, 2, 2);
    
    //ref = Eigen::DenseBase<Eigen::MatrixXd>::BlockXpr(input.inputs[0]->block(1, 1, 2, 2));
//    ref = input.inputs[0]->block(1, 1, 2, 2);
    //refs[0](0, 0) = 2;
    //refs.clear();
    
    //refs[0](0, 0) = 2;
    std::cout << input.outputs[0](1,0);
    convolutional_layer conv(&input, 1);
    input.forward();
    std::cout << conv.outputs[0];
    return 0;
}
