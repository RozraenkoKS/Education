#include <iostream>

unsigned int number_of_digits(auto i) {
	return i > 0 ? log10(i) + 1 : 1;
}
void print_pascal_triangle(unsigned int n)
{
	if (n == 1) {
		std::cout << 1 << std::endl;
		return;
	}
	for (auto i = 0; i < n; i++) {
		auto x = 1;
		std::fill_n(std::ostream_iterator<char>(std::cout), (n - i - 1) * (n / 2), ' ');
		for (int j = 0; j <= i; j++) {
			auto y = x;
			x = x * (i - j) / (j + 1);
			auto maxlen = number_of_digits(x) - 1;
			std::cout << y;
			std::fill_n(std::ostream_iterator<char>(std::cout), n - 1 - maxlen - n % 2, ' ');
		}
		std::cout << std::endl;
	}
}

int main()
{
	auto n = 0;
	std::cout << "Levels (up to 10): ";
	std::cin >> n;
	if (n > 10)
		std::cout << "Value too large" << std::endl;
	else
		print_pascal_triangle(n);
}