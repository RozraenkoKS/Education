#include <iostream>
#include <variant>
#include <utility>
#include <cmath>

std::variant<std::monostate, std::pair<double, double>, double> calculateRoots(double a, double b, double c) {
    double D = b * b - 4 * a * c;

    if (D < 0) {
        return std::monostate{};
    }
    else if (0 == D) {
        auto x = (-b) / (2.0 * a);
        return x;
    }
    else {
        auto x1 = (-b - sqrt(D)) / (2.0 * a);
        auto x2 = (-b + sqrt(D)) / (2.0 * a);
        return std::make_pair(x1, x2);
    }
}

class Visitor {
public:
    void operator()(const std::monostate& answer) const {
        std::cout << "No real roots" << std::endl;
    }
    void operator()(const std::pair<double, double>& answer) const {
        std::cout << "Two real roots: " << answer.first << " and " << answer.second << std::endl;
    }
    void operator()(const double answer) const {
        std::cout << "One real root: " << answer << std::endl;
    }
};

int main() {
    double a{};
    double b{};
    double c{};

    std::cout << "Enter coefficients a, b, and c: ";
    std::cin >> a >> b >> c;
    auto answer = calculateRoots(a, b, c);

    std::visit(Visitor{}, answer);

    return 0;
}