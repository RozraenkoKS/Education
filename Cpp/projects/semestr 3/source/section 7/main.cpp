#include <iostream>
#include "Circle.hpp"

int main() {
    Geometry::Circle circle{ 2 };

    std::cout << "Current circle perimeter is " << circle.circle_length() << '\n';

    return 0;
}
