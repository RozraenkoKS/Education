#include <iostream>
#include <variant>
#include <string>
class Line {
public:
	explicit Line(double x, double y, double z): a(x), b(y), c(z){
	}
	auto get_coefficient_a() const{
		return a;
	}
	auto get_coefficient_b() const{
		return b;
	}
	auto get_coefficient_c() const{
		return c;
	}
public:
	double a;
	double b;
	double c;
};


class Point {
public:
	explicit Point(double x, double y) : x0(x), y0(y) {
	}
	auto get_abscissa() const{
		return x0;
	}
	auto get_ordinate() const{
		return y0;
	}
public:
	double x0;
	double y0;
};


auto det(double a, double b, double c, double d) {
	return a * d - b * c;
}


std::variant< std::monostate, std::string, Point> intersection_point(const Line& l1, const Line& l2) {
	double det0 = det(l1.a, l1.b, l2.a, l2.b);
	if (det0 != 0) {
		return Point(det(-l1.c, l1.b, -l2.c, l2.b) / det0, det(l1.a, -l1.c, l2.a, -l2.c) / det0);
	}
	else if (det0 == 0 && det(l1.c, l1.a, l2.c, l2.a) == 0 && det(l1.c, l1.b, l2.c, l2.b) == 0) {
		return "Infinite intersection";
	}
	else {
		return std::monostate{};
	}
}


int main() {
	double a1, b1, c1, a2, b2, c2;
	std::cout << "Enter coefficients for Line 1 (a, b, c): ";
	std::cin >> a1 >> b1 >> c1;

	std::cout << "Enter coefficients for Line 2 (a, b, c): ";
	std::cin >> a2 >> b2 >> c2;
	Line l1(a1, b1, c1);
	Line l2(a2, b2, c2);


	auto answer = intersection_point(l1,l2);
	if (std::holds_alternative<std::monostate>(answer)) {
		std::cout << "No intersection" << std::endl;
	}
	else if (std::holds_alternative<std::string>(answer)) {
		auto str = std::get<std::string>(answer);
		std::cout << str;
	}
	else {
		auto point = std::get<Point>(answer);
		std::cout << "Lines intersect at: (" << point.get_abscissa() << ", " << point.get_ordinate() << ")" << std::endl;
	}
	return 0;
}
