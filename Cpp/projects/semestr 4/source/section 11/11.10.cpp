#include <valarray>
#include <iostream>
#include <vector>

int main() {
	std::size_t dim = 3;

	std::valarray<int> v1{ 1, 2, 3 };
	std::valarray<int> v2{ 0, 2, 1 };

	std::cout << "v1 + v2 elements are: ";
	for (auto element : v1 + v2) {
		std::cout << element << ' ';
	}
	std::cout << std::endl;

	std::cout << "2 * v1 elements are: ";
	for (auto element : 2 * v1) {
		std::cout << element << ' ';
	}
	std::cout << std::endl;

	std::cout << "v1 + 1 elements are: ";
	for (auto element : v1 + 1) {
		std::cout << element << ' ';
	}
	std::cout << std::endl;

	std::valarray<double> d_v1 = { 1.0, 2.0, 3.0 };
	std::cout << "exp(v1) elements are: ";
	for (auto element : exp(d_v1)) {
		std::cout << element << ' ';
	}
	std::cout << std::endl;

	std::cout << "v1 % 2 elements are: ";
	for (auto element : v1.apply([](int element) { return element % 2; })) {
		std::cout << element << ' ';
	}
	std::cout << std::endl;

	std::cout << "v1 * v2 elements are: ";
	for (auto element : v1 * v2) {
		std::cout << element << ' ';
	}
	std::cout << std::endl;

}