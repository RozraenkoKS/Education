#include <iostream>
#include <iterator>
#include <numeric>
#include <utility>
#include <vector>
#include <random>

auto f(auto x, auto y) {
	return x > y;
}

auto g(auto x, auto y) {
	return x < y;
}

void insertion_sort(bool (*f)(int, int), std::vector < int >& v, std::size_t l, std::size_t r) // note: o(n^2) complexity 
{
	for (auto i = l + 1; i < r; ++i)
	{
		for (auto j = i; j > l; --j)
		{
			if (f(v[j - 1], v[j]))
			{
				std::swap(v[j], v[j - 1]);
			}
		}
	}
}

void merge_sort(bool (*f)(int, int), std::vector < int >& v, std::size_t l, std::size_t m, std::size_t r)
{
	const auto begin = l, end = m;

	std::vector < int > t(r - l, 0); // note: one additional container instead of two

	for (auto& e : t)
	{
		e = v[((l < end && ((m < r && f(v[l], v[m])) || (m == r))) ? l++ : m++)];
	}

	for (std::size_t i = 0; i < std::size(t); ++i) v[begin + i] = t[i];
}

void merge_sort(bool (*f)(int, int), std::vector < int >& v, std::size_t l, std::size_t r) // note: o(n*log(n)) complexity (amortized)
{
	if (static const std::size_t block = 64; r - l <= block)
	{
		insertion_sort(f, v, l, r); // good: double nested loop instead of recursive calls
	}
	else
	{
		auto m = std::midpoint(l, r);

		merge_sort(f, v, l, m);
		merge_sort(f, v, m, r);
		merge_sort(f, v, l, m, r);
	}
}

int main()
{
	const std::size_t n = 5;
	std::vector < int > vector(n, 0);

	std::mt19937 engine(std::random_device{}());
	std::uniform_int_distribution distribution(1, 999);

	for (auto value = static_cast <int> (n); auto & element : vector) element = distribution(engine);
	for (auto element : vector) std::cout << element << ' ';
	std::cout << std::endl;

	merge_sort(f, vector, 0, n); // good: half-open intervals preferred in c++

	for (auto element : vector) std::cout << element << ' ';
	std::cout << std::endl;

	merge_sort(g, vector, 0, n);

	for (auto element : vector) std::cout << element << ' ';
	std::cout << std::endl;

	return 0;
}
