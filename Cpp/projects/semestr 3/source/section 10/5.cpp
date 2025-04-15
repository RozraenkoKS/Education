#include <iostream>
#include <numeric>
#include <stdexcept>

class Error : public std::exception {
public:
	explicit Error(const std::string& message, int code):
		std::exception(message.c_str()), m_code(code) {}

	const char* what() const override { return "error"; }
private:
	int m_code;
};

class Ratio
{
public:

	using int_t = int;

public:

	Ratio(int_t n = 0, int_t d = 1) :
		m_numerator(n), m_denominator(d)
	{
	if (m_denominator == 0) throw Error("Divide by zero error in fraction!", 42);

	if (m_denominator < 0) 
	{
		m_numerator *= -1;
		m_denominator *= -1;
	}

		reduce();
	}

	explicit operator double() const 
	{
		return 1.0 * m_numerator / m_denominator;
	}

private:

	void reduce()
	{
		auto gcd = std::gcd(m_numerator, m_denominator);

		m_numerator /= gcd;
		m_denominator /= gcd;
	}

public:

	auto numerator() const
	{
		return m_numerator;
	}

	auto denominator() const
	{
		return m_denominator;
	}

public:

	void print() const 
	{
		std::cout << m_numerator << '/' << m_denominator << std::endl;
	}

public:

	auto& operator+=(Ratio other)
	{
		if (other.m_denominator == 0) throw Error("Divide by zero error in fraction!", 42);
		auto lcm = std::lcm(m_denominator, other.m_denominator);

		m_numerator = m_numerator * (lcm / m_denominator) +
			other.m_numerator * (lcm / other.m_denominator);

		m_denominator = lcm;

		reduce();

		return *this;
	}

	auto& operator-=(Ratio other)
	{
		return (*this += (other.m_numerator *= -1));
	}

	auto& operator*=(Ratio other)
	{
		m_numerator *= other.m_numerator;
		m_denominator *= other.m_denominator;

		reduce();

		return *this;
	}

	auto& operator/=(Ratio other)
	{
		return (*this *= Ratio(other.m_denominator, other.m_numerator));
	}

public:

	auto& operator++()
	{
		m_numerator += m_denominator;

		return *this;
	}

	auto& operator--()
	{
		m_numerator -= m_denominator;

		return *this;
	}

	auto operator++(int)
	{
		Ratio tmp(*this);

		++(*this);

		return tmp;

	}

	auto operator--(int)
	{
		Ratio tmp(*this);

		--(*this);

		return tmp;
	}

private:

	int_t m_numerator;
	int_t m_denominator;

};

auto operator+(Ratio lhs, Ratio rhs) 
{
	return (lhs += rhs);
}

auto operator-(Ratio lhs, Ratio rhs) 
{
	return (lhs -= rhs);
}

auto operator*(Ratio lhs, Ratio rhs) 
{
	return (lhs *= rhs);
}

auto operator/(Ratio lhs, Ratio rhs) 
{
	return (lhs /= rhs);
}

auto operator<(Ratio lhs, Ratio rhs)
{
	return static_cast <double> (lhs) < static_cast <double> (rhs);
}

auto operator>(Ratio lhs, Ratio rhs)
{
	return (rhs < lhs);
}

auto operator<=(Ratio lhs, Ratio rhs)
{
	return !(lhs > rhs);
}

auto operator>=(Ratio lhs, Ratio rhs)
{
	return !(lhs < rhs);
}

auto operator==(Ratio lhs, Ratio rhs)
{
	return (!(lhs < rhs) && !(rhs < lhs));
}

auto operator!=(Ratio lhs, Ratio rhs)
{
	return !(lhs == rhs);
}

int main()
{
	try {
		//Ratio r0(1, 0); --> error
		Ratio r1;
		Ratio r2(2);
		Ratio r3 = 3;
		Ratio r4(-5, 10);

		std::cout << static_cast <double> (r4) << std::endl;

		(r4 += 10).print();
		(r4 -= r1).print();
		(r4 *= r2).print();
		(r4 /= r3).print();
		(++r4).print();
		(--r4).print();
		(r4++).print();
		(r4--).print();

		(10 + r4).print();
		(r4 - 10).print();
		(r4 * r3).print();
		(r4 / r2).print();

		std::cout << (r3 < r4) << std::endl;
		std::cout << (r3 > r4) << std::endl;

		std::cout << (r3 <= r4) << std::endl;
		std::cout << (r3 >= r4) << std::endl;

		std::cout << (r3 == r4) << std::endl;
		std::cout << (r3 != r4) << std::endl;


	}
	catch (std::exception& e) {
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	return 0;
}
	