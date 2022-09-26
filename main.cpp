#include "Matrix.hpp"

int main(void)
{
    Matrix<3, 3> A = {{1, 2, 3},
                      {1, 2, 3},
                      {1, 2, 3}};
    Matrix<3, 3> B = {{0, 2, 4},
                      {2, 5, 3},
                      {2, 1, 4}};
    Matrix<3, 4> C = {{13, 9, 7, 15},
                      {8, 7, 4, 6},
                      {6, 4, 0, 3}};
    Matrix<3, 3> good_sum = A+B;
    std::cout << "Matrix sum" << std::endl;
    std::cout << good_sum;
    // Matrix<3, 3> bad_sum = A+C;

    std::cout << "Transposed" << std::endl;
   Matrix<4, 3> D = C.transposed();
    std::cout << D;

    Matrix<1, 3> E {{3, 4, 2}};
    Matrix<3, 4> F(C);
    std::cout << "Multiplying E\n" << E
    << " by C\n" << C << "Returns\n";
    Matrix<1, 4> G = E * C;
    std::cout << G;
    Matrix<2, 3> H = {{1, 2, 3},
                      {4, 5, 6}};
    Matrix<3, 2> I = {{7, 8},
                      {9, 10},
                      {11, 12}};
    Matrix<2, 2> J = H * I;
    std::cout << J;
}