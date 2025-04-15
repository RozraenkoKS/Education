#pragma once

namespace Geometry {
    class Circle {
    public:
        Circle(double radius = 0.0);

        void print() const;

        double get_radius() const;

        double circle_area() const;

        double circle_length() const;

    private:
        double m_radius;
        static double pi;
    };
}
