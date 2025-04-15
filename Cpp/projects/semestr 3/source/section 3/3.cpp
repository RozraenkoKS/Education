#include <iostream>
class Speed
{
private:
	double m_speed_si{};
	double m_speed_sgs{};
	double m_speed_out{};

public:
	static inline int const sms = 100;
	static inline double const kmh = 3.6;

public:
	Speed(double speed = 0)
		: m_speed_si{ speed }, 
		m_speed_sgs{ speed * sms },
		m_speed_out { speed * kmh }
	{
	}
	void print()
	{
		std::cout << "Current speed m/s " << m_speed_si << '\n';
		std::cout << "Current speed km/h " << m_speed_out << '\n';
		std::cout << "Current speed sm/s " << m_speed_sgs << '\n' << '\n';
	}

public:
	auto get_speed_si() const
	{
		return m_speed_si;
	}
	auto get_speed_sgs() const
	{
		return m_speed_sgs;
	}
	auto get_speed_out() const
	{
		return m_speed_out;
	}

	void set_speed(double speed)
	{
		m_speed_si = speed;
		m_speed_sgs = speed * sms;
		m_speed_out = speed / kmh;
	}
};
int main()
{
	Speed s{ 10 };
	s.print();

	std::cout << "Curent speed m/s: " << s.get_speed_si() << '\n';
	std::cout << "Curent speed sm/s: " << s.get_speed_sgs() << '\n';
	std::cout << "Curent speed km/h: " << s.get_speed_out() << '\n' << '\n';

	s.set_speed(12.5);
	s.print();

	std::cout << "Curent speed m/s: " << s.get_speed_si() << '\n';
	std::cout << "Curent speed sm/s: " << s.get_speed_sgs() << '\n';
	std::cout << "Curent speed km/h: " << s.get_speed_out() << '\n' << '\n';

	return 0;

}