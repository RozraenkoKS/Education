#include <iostream>
#include <cmath> 


class Shape
{
public:
	virtual ~Shape()
	{}
	virtual double Area() = 0
	{}
	virtual double Perimeter() = 0
	{}
};
class Ellipse: public Shape
{
public:
	static inline double const pi = 3.14;

public:
	Ellipse(double a = 0, double b = 0) : m_a{ a }, m_b{ b }
	{
		std::cout << "Ellipse constructed" << '\n';
	}

	void print() const
	{
		std::cout << "Ellipse a axis is: " << m_a << '\n';
		std::cout << "Ellipse b axis is: " << m_b << '\n';
	}

public:
	double Area() override
	{
		return pi * m_a * m_b;
	}

	double Perimeter() override
	{
		return pi * (m_a + m_b);
	}
	 
protected:
	double m_a{};
	double m_b{};
};

class Circle : public Ellipse
{

public:
	Circle(double r = 0) : Ellipse(r, r)
	{
		std::cout << "Circle constructed" << '\n';
	}

	void print() const
	{
		std::cout << "Circle radius is: " << m_a << '\n';
	}
};

class Polygon : public Shape
{
};

class Rectangle : public Polygon
{
public:
	Rectangle(double a = 0, double b = 0) : m_a{ a }, m_b{ b }
	{
		std::cout << "Rectangle constructed" << '\n';
	}

	void print() const
	{
		std::cout << "Rectangle a side is: " << m_a << '\n';
		std::cout << "Rectangle b side is: " << m_b << '\n';
	}

public:
	double Area() override
	{
		return m_a * m_b;
	}

	double Perimeter() override
	{
		return 2 * (m_a + m_b);
	}

protected:
	double m_a{};
	double m_b{};
};

class Square : public Rectangle
{

public:
	Square(double r = 0) : Rectangle(r, r)
	{
		std::cout << "Square constructed" << '\n';
	}

	void print() const
	{
		std::cout << "Square side is: " << m_a << '\n';
	}
};


class Triangle : public Polygon
{

public:
	Triangle(double a = 0, double b = 0, double c = 0, double h = 0) : m_a{ a }, m_b{ b }, m_c{ c }
	{
		std::cout << "Triangle constructed" << '\n';
	}

	void print() const
	{
		std::cout << "Triangle a side is: " << m_a << '\n';
		std::cout << "Triangle b side is: " << m_b << '\n';
		std::cout << "Triangle c side is: " << m_c << '\n';
	}

public:
	double Area() override
	{
		return 1/4 * sqrt(4 * m_a * m_a * m_b * m_b - pow((m_a * m_a + m_b * m_b - m_c * m_c), 2));
	}
	double Perimeter()
	{
		return m_a + m_b + m_c;
	};


protected:
	double m_a{};
	double m_b{};
	double m_c{};
};



int main()
{

	const auto size = 5;

	Shape* p1{ new Triangle{ 3, 4, 5 } };
	Shape* p2{ new Circle{ 2 } };
	Shape* p3{ new Ellipse{ 3, 4 } };
	Shape* p4{ new Rectangle{ 3, 4 } };
	Shape* p5{ new Square{ 4 } };

	Shape* pointers[size]{ p1, p2, p3, p4, p5};

	for (auto i = 0; i < size; ++i)
	{
		std::cout << pointers[i]->Area() << '\n';
		std::cout << pointers[i]->Perimeter() << '\n' << '\n';
	}
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	return 0;
}