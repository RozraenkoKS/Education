#include <iostream>
consteval bool is_prime(int n) {
	if (n % 2 == 0){
		return n == 2;
	}
	int d{ 3 };
	while (d * d <= n && n % d != 0) {
		d += 2;
	}
	return d * d > n;
}

consteval int prime(int n) {
	int counter{ 0 };
	int i{ 2 }; 
	while (counter < n) {
		if (is_prime(i)) {
			counter += 1;

		}
		i++;
	}
	return i - 1;
}

int main() {
	constexpr auto n = 2;
	constexpr auto result = prime(n);
	std::cout << result;
	return 0;
}



