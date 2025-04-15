#include <iostream>
int main()
{
	int x{};
	int y{};
	std::cin >> x >> y;
	y = y - x;
	x = x + y;
	y = x - y;
	std::cout << x << '\n' << y;
	return 0;
}