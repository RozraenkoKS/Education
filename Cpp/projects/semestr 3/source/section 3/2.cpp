#include <iostream>
class Triangle
{
public:
	Triangle(double side = 0.0, double height = 0.0)
		: m_side{ side }, m_height{ height }
	{
	}
	void print()
	{
		std::cout << "Triangle side is " << m_side << '\n';
		std::cout << "Triangle hight is " << m_height << '\n';
	}
public:
	auto get_side() const
	{
		return m_side;
	}
	auto get_height() const
	{
		return m_height;
	}

public:
	auto triangle_area()
	{
		return 0.5 * m_side * m_height;
	}

private:
	double m_side{};
	double m_height{};
};

class Rectangle
{
public:
	Rectangle(double side_1 = 0.0, double side_2 = 0.0)
		: m_side_1{ side_1 }, m_side_2{ side_2 }
	{
	}
	void print()
	{
		std::cout << "Rectangle side_1 is " << m_side_1 << '\n';
		std::cout << "Rectangle side_2 is " << m_side_2 << '\n';
	}
public:
	auto get_side_1() const
	{
		return m_side_1;
	}
	auto get_side_2() const
	{
		return m_side_2;
	}
public:
	auto rectangle_area()
	{
		return m_side_1 * m_side_2;
	}
	auto rectangle_perimetr()
	{
		return 2 * (m_side_1 + m_side_2);
	}

private:
	double m_side_1{};
	double m_side_2{};

};

class Circle
{
public:
	static double pi;
public:
	Circle(double radius = 0.0)
		: m_radius{ radius }
	{
	}
	void print()
	{
		std::cout << "Circle radius is " << m_radius << '\n';
	}
public:
	auto get_radius() const
	{
		return m_radius;
	}
public:
	auto circle_area()
	{
		return  pi * m_radius * m_radius;
	}
	auto circle_length()
	{
		return 2 * pi * m_radius;
	}

private:
	double m_radius{};
};

double Circle::pi{ 3.14 };

int main()
{
	Triangle triangle{5, 6};

	std::cout << "Current triangle area is " << triangle.triangle_area() << '\n';

	triangle.print();

	std::cout << "Current triangle side is " << triangle.get_side() << '\n';
	std::cout << "Current triangle hight is " << triangle.get_height() << '\n';

	triangle.print();

	std::cout << "Current triangle area is " << triangle.triangle_area() << '\n';

	Circle circle{ 2 };

	std::cout << "Current circle perimetr is " << circle.circle_length() << '\n';
	return 0;
}