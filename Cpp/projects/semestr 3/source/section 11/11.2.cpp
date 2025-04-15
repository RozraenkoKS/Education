#include <iostream>
template < int N > struct Fibonacci {
	static_assert(N >= 0);
	static const int value = Fibonacci < N - 1 > ::value + Fibonacci < N - 2 > ::value; };
template <> struct Fibonacci < 0 > { static const int value = { 0 }; };
template <> struct Fibonacci < 1 > { static const int value = { 1 }; };
template < int N > static const int fibonacci_v = Fibonacci < N > ::value;
int main() {
	constexpr int fibonacci_v1 = fibonacci_v < 10 >;
	std::cout << fibonacci_v1 << std::endl;
	return 0;
}