#include "Circle.hpp"
#include <iostream>

namespace Geometry {
    Circle::Circle(double radius)
        : m_radius(radius) {
    }

    void Circle::print() const {
        std::cout << "Circle radius is " << m_radius << '\n';
    }

    double Circle::get_radius() const {
        return m_radius;
    }

    double Circle::circle_area() const {
        return pi * m_radius * m_radius;
    }

    double Circle::circle_length() const {
        return 2 * pi * m_radius;
    }

    double Circle::pi = 3.14;  
}


