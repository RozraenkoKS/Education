#include <iostream>
#include <cassert>

/*template < int N > struct Factorial {
	static constexpr int value = N * Factorial < N - 1 > ::value;
};
template <> struct Factorial < 0 > { static const int value = 1; };
template < int N > const int factorial_v = Factorial < N > ::value;

template <int N, int M> struct BinCoef {
	static_assert(N >= M);
	static constexpr int value =  factorial_v< N > / factorial_v< M > / factorial_v< N - M >;
};
template < int N, int M > const int binCoef_v = BinCoef < N, M > ::value;

int main() {
	constexpr auto N{ 6 };
	constexpr auto M{ 2 };
	constexpr auto binCoef_v1 = binCoef_v < N, M >;
	std::cout << binCoef_v1 << std::endl;
	return 0;
}*/

template < int N, int M > struct BinCoef {
	static_assert(N >= M);
	static const int value = BinCoef < N - 1, M - 1 > ::value + BinCoef < N - 1, M > ::value;
};
template <int N> struct BinCoef < N, 0 > { static const int value = { 1 }; };
template <int N> struct BinCoef < N, N > { static const int value = { 1 }; };

template < int N, int M > static const int binCoef_v = BinCoef < N, M > ::value;
int main() {
	constexpr int binCoef_v1 = binCoef_v < 8, 5 >;
	std::cout << binCoef_v1 << std::endl;
	return 0;
}