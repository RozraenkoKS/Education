#include <iostream>
int main()
{
	int x{};
	int y{};
	std::cin >> x >> y;
	x = bool(x);
	y = bool(y);
	std::cout << !x * y + !y * x;
	return 0;
}