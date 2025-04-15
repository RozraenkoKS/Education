#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>

void print(auto& v) {
    for (auto element : v) {
        std::cout << element << ' ';
    }; std::cout << std::endl;
}

int main() {
    // Initializing a vector and printing its contents
    std::vector<int> vector(10, 0);
    std::cout << "Initial vector: ";
    print(vector);

    // Filling the vector with value 5
    std::ranges::fill(vector, 5);
    std::cout << "Vector after std::fill: ";
    print(vector);

    // Removing character 'H' from the string
    std::string str("Hello world");
    auto arr1 = std::ranges::remove_if(std::begin(str), std::end(str), [](auto x) {return x == 'H';});
    str.erase(arr1.begin(), arr1.end());
    std::cout << "String after removing 'H': " << str << std::endl;

    // Filling the vector with a sequence of numbers
    std::ranges::iota(vector, -10);
    std::cout << "Vector after std::iota: ";
    print(vector);

    // Finding element -5 in the vector
    const int element = -5;
    auto it2 = std::ranges::find_if(std::begin(vector), std::end(vector), [element](auto x) {return x == element;});
    it2 == std::end(vector)
        ? std::cout << "Element not found" << std::endl
        : std::cout << "Found element -5: " << *it2 << std::endl;

    // Setting an element in the middle of the vector to 42
    vector[vector.size() / 2] = 42;
    std::cout << "Vector after setting middle element to 42: ";
    print(vector);

    // Using std::partition to partition even and odd elements in the vector
    std::ranges::partition(vector, [](auto x) { return x % 2 == 0; });
    std::cout << "Vector after partitioning even and odd elements: ";
    print(vector);

    // Using views and std::transform to double each element in the vector
    auto double_vector = vector | std::views::transform([](auto x) { return x * 2; });
    std::cout << "Vector after doubling each element: ";
    print(vector);

    // Finding the minimum element in the vector
    auto min_element = std::ranges::min_element(vector);
    std::cout << "Minimum element in vector: " << *min_element << std::endl;

    // Finding the maximum element in the vector
    auto max_element = std::ranges::max_element(vector);
    std::cout << "Maximum element in vector: " << *max_element << std::endl;

    // Counting the occurrences of 0 in the vector
    int count_of_zeros = std::ranges::count(vector, 0);
    std::cout << "Count of zeros in vector: " << count_of_zeros << std::endl;

    // Watching negative elements in the vector with 0 using views
    auto replace_view = vector | std::views::transform([](auto x) { return std::max(x, 0); });
    std::cout << "Vector after replacing negative elements: ";
    print(vector);

    std::ranges::fill(vector.begin(), vector.end(), 0);
    vector[vector.size() / 2] = 42;
    print(vector);

    // Removing consecutive duplicates from the vector using views
    const auto arr2 = std::ranges::unique(vector);
    // Vector now holds {1 2 1 3 4 5 4 x x x}, where 'x' is indeterminate
    vector.erase(std::begin(arr2), std::end(arr2));
    std::cout << "Vector after removing consecutive duplicates: ";
    print(vector);

    return 0;
}
