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
        double x = (-b) / (2.0 * a);
        return x;
    }
    else {
        double x1 = (-b - sqrt(D)) / (2.0 * a);
        double x2 = (-b + sqrt(D)) / (2.0 * a);
        return std::make_pair(x1, x2);
    }
}

int main() {
    double a{};
    double b{};
    double c{};

    std::cout << "Enter coefficients a, b, and c: ";
    std::cin >> a >> b >> c;
    std::variant<std::monostate, std::pair<double, double>, double> answer = calculateRoots(a, b, c);
    if (std::holds_alternative<std::monostate>(answer)) {
        std::cout << "No real roots" << std::endl;
    }
    else if (std::holds_alternative<double>(answer)) {
        double x = std::get<double>(answer);
        std::cout << "One real root: " << x << std::endl;
    }
    else {
        auto roots = std::get<std::pair<double, double>>(answer);
        std::cout << "Two real roots: " << roots.first << " and " << roots.second << std::endl;
    }

    return 0;
}
