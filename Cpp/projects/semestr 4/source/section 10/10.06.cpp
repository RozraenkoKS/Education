#include <iostream>
#include <vector>

template <typename T>
[[nodiscard]] auto binary_search(auto left, auto right, T target) // note: O(log(N)) complexity
{
	auto end = right;
	if (left == right)
	{
		return right; // good: nullptr is better than special index value like INT_MAX or -1
	}

	if (std::distance(left, right) == 1)
	{
		return (*left == target ? left : right);
	}

	while (left < right) // good: one comparison in selection condition with two branches in the loop
	{
		if (auto middle = std::next(left, std::distance(left, right) / 2); *middle < target) // good: optimized for overflows
		{
			left = ++middle;
		}
		else
		{
			right = middle;
		}
	}

	return (*left == target ? left : end); // good: one additional comparison after the loop
}

int main()
{
	std::vector<int> vector{ 1, 3, 4, 5, 6, 7, 8 }; // note: sorted array, consider std::vector with iterators

	const auto size = std::size(vector); // note: prefer std::size over this way

	for (auto i : vector)
	{
		std::cout << "index of " << i << " in array: ";

		if (const auto it = binary_search(std::begin(vector), std::end(vector), i); it == std::end(vector)) // note: closed interval
		{
			std::cout << "not found" << std::endl; // note: get index through pointer arithmetic
		}
		else
		{
			std::cout << std::distance(std::begin(vector), it) << std::endl;
		}
	}

	return 0;
}


