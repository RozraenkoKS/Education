#include <iostream>

template <typename T, typename... Types>
auto func_user(T x, Types... args) {
    return x(args...);
}

int add(int a, int b) {
    return a + b;
}

double multiply(double a, double b) {
    return a * b;
}

int main() {
    int result1 = func_user(add, 2, 3);
    std::cout << "Result of add: " << result1 << std::endl;

    double result2 = func_user(multiply, 2.5, 3.0);
    std::cout << "Result of multiply: " << result2 << std::endl;

    return 0;
}