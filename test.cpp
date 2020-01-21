#include <iostream>
#include <armadillo>
#include <complex>

using namespace std;
using namespace arma;

int main()
{
    mat A = randu<mat>(5,5);
    vec b = randu<vec>(5);
    mat B = randu<mat>(5,5);

    vec x1 = solve(A, b);

    vec x2;
    bool status = solve(x2, A, b);

    mat X1 = solve(A, B);

    mat X2 = solve(A, B, solve_opts::fast);  // enable fast mode

    mat X3 = solve(trimatu(A), B);  // indicate that A is triangular;
    
    X1.print("X1=");
    X1.save("A.txt", raw_ascii);

    std::complex<double> x( 2, 0 );

    std::cout << std::real( 1 ) / x << std::endl;
    return 0;
}
