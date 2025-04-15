#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
#include <list>
#include <random>
#include <functional>


int main() {
	std::list<int> l(10);

	std::mt19937 engine{ std::random_device{}() };
	std::uniform_int_distribution<int> dis(0, 100);

	std::ranges::generate(l.begin(), l.end(), [&engine, &dis]() { return dis(engine); });

	for (auto element : l) {
		std::cout << element << ' ';
	}; std::cout << std::endl;

	std::vector<std::reference_wrapper<int>> v(l.begin(), l.end());

	std::ranges::sort(v);

	for (auto element : v) {
		std::cout << element << ' ';
	}; std::cout << std::endl;

	for (auto element : l) {
		std::cout << element << ' ';
	}; std::cout << std::endl;
	return 0;
}