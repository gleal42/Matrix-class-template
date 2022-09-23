#include "Matrix.hpp"

int main(void)
{
    Matrix<3, 3> A = {{1, 2, 3},
                      {1, 2, 3},
                      {1, 2, 3}};
    Matrix<3, 3> B = {{0, 2, 4},
                      {2, 5, 3},
                      {2, 1, 4}};
    Matrix<3, 4> C = {{0, 2, 4, 4},
                      {2, 5, 3, 4},
                      {2, 1, 4, 4}};
    Matrix good_sum = A+B;
    std::cout << "Matrix sum" << std::endl;
    std::cout << good_sum;
    // Matrix<3, 3> bad_sum = A+C;
}