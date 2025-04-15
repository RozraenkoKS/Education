#include <variant>
#include <cassert> 
#include <cstdint> 
#include <iostream>
#include <utility>
#include <cmath>
consteval std::variant<std::monostate, std::int64_t> intpow(std::int64_t a, int x) {
	if (a == 0){
		if (x == 0){
			return std::monostate{};
		} else {
			return 0;
		}
	}
	std::int64_t result{ 1 };
	while (x > 0) {
		if (x & 1) {
			result *= a;
		}
		x /= 2;
		a *= a;
	}
	return result;
}
int main() {
	constexpr auto a = 2;
	static_assert (a >= 0 && "intpow: exp parameter has negative value");
	constexpr auto x = 3;
	constexpr auto answer = intpow(a, x);
	if (std::holds_alternative<std::monostate>(answer)) {
		std::cout << "No real answer" << std::endl;
	} else {
		constexpr auto result = std::get<std::int64_t>(answer);
		std::cout << "a to the power of x is: " << result << std::endl;
	}
	return 0;
}
