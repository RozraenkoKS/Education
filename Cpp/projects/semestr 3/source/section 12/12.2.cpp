#include <iostream>
#include <variant>
#include <utility>
#include <cmath>
#include <complex>
using namespace std;
std::pair<complex<double>, complex<double>> calculateRoots(complex<double> a, complex<double> b, complex<double> c) {
    complex<double> four = 4;
    auto D = b * b - four * a * c; 
    auto x1 = (-b - sqrt(D)) / (2.0 * a);
    auto x2 = (-b + sqrt(D)) / (2.0 * a);
    return std::make_pair(x1, x2);
}
int main() {
    complex<double> a{};
    complex<double> b{};
    complex<double> c{};

    std::cout << "Enter real coefficients a, b, and c: ";
    std::cin >> a >> b >> c;
    auto roots = calculateRoots(a, b, c);
    std::cout << "Real part of the first root: " << roots.first.real() << std::endl;  
    std::cout << "Imaginary part of the first root: " << roots.first.imag() << std::endl;  
    std::cout << "Absolute value of the first root: " << std::abs(roots.first) << std::endl;  
    std::cout << "Argument of the first root: " << std::arg(roots.first) << std::endl;  
    std::cout << "Real part of the second root: " << roots.second.real() << std::endl;  
    std::cout << "Imaginary part of the second root: " << roots.second.imag() << std::endl;  
    std::cout << "Absolute value of the second root: " << std::abs(roots.second) << std::endl;  
    std::cout << "Argument of the second root: " << std::arg(roots.second) << std::endl; 
    std::cout << "The coefficient b/a due to Vietta: " << -(roots.first + roots.second).real() << std::endl;
    std::cout << "The coefficient c/a dut to Vietta: " << (roots.first * roots.second).real() << std::endl;
    if (roots.first.imag() == 0) {
        std::cout << "The first root is: " << roots.first.real() << std::endl;
    }
    else {
        std::cout << "The first root is: " << roots.first.real() << (roots.first.imag() > 0 ? " + " : " - ") << abs(roots.first.imag()) << "i" << std::endl;
    }
    if (roots.second.imag() == 0) {
        std::cout << "The second root is: " << roots.second.real() << std::endl;
    }
    else {
        std::cout << "The second root is: " << roots.second.real() << (roots.second.imag() > 0 ? " + " : " - ") << abs(roots.second.imag()) << "i" << std::endl;
    }
    return 0;
}
