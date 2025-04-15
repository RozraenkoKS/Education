#include <iostream>
constexpr double eCalculation(double epsilon) {
	double den{ 1.0 };
	int counter{ 1 };
	double e = { 1.0 };
	while ((1.0 / den) > epsilon) {
		counter += 1;
		e += 1.0 / den;
		den *= counter;
	}
	return e;
}

int main() {
	constexpr auto epsilon{ 0.001 };
	constexpr auto result = eCalculation(epsilon);
	std::cout << result;
	return 0;
}