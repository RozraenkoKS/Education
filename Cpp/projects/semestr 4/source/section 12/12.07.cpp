#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>




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
    std::fill(std::begin(vector), std::end(vector), 5);
    std::cout << "Vector after std::fill: ";
    print(vector);

    // Removing character 'H' from the string
    std::string str("Hello world");
    auto it1 = std::remove_if(std::begin(str), std::end(str), [](auto x) {return x == 'H';});
    str.erase(it1, str.end());
    std::cout << "String after removing 'H': ";
    print(str);

    // Filling the vector with a sequence of numbers
    std::iota(std::begin(vector), vector.end(), -10);
    std::cout << "Vector after std::iota: ";
    print(vector);

    // Finding element -5 in the vector
    const int element = -5;
    auto it2 = std::find_if(std::begin(vector), std::end(vector), [element](auto x) {return x == element;});
    it2 == std::end(vector)
        ? std::cout << "Element not found" << std::endl
        : std::cout << "Found element -5: " << *it2 << std::endl;

    // Setting an element in the middle of the vector to 42
    vector[vector.size() / 2] = 42;
    std::cout << "Vector after setting middle element to 42: ";
    print(vector);

    // Using std::partition to partition even and odd elements in the vector
    std::partition(std::begin(vector), std::end(vector), [](auto x) { return x % 2 == 0; });
    std::cout << "Vector after partitioning even and odd elements: ";
    print(vector);

    // Using std::transform to double each element in the vector
    std::transform(std::begin(vector), std::end(vector), std::begin(vector), [](auto x) { return x * 2; });
    std::cout << "Vector after doubling each element: ";
    print(vector);

    // Finding the minimum element in the vector
    auto min_element = std::min_element(std::begin(vector), std::end(vector));
    std::cout << "Minimum element in vector: " << *min_element << std::endl;

    // Finding the maximum element in the vector
    auto max_element = std::max_element(std::begin(vector), std::end(vector));
    std::cout << "Maximum element in vector: " << *max_element << std::endl;

    // Counting the occurrences of 0 in the vector
    int count_of_zeros = std::count(std::begin(vector), std::end(vector), 0);
    std::cout << "Count of zeros in vector: " << count_of_zeros << std::endl;

    // Replacing negative elements in the vector with 0
    std::replace_if(std::begin(vector), std::end(vector), [](auto x) { return x < 0;}, 0);
    std::cout << "Vector after replacing negative elements: ";
    print(vector);

    // Removing consecutive duplicates from the vector
    auto it3 = std::unique(std::begin(vector), std::end(vector));
    vector.erase(it3, vector.end());
    std::cout << "Vector after removing consecutive duplicates: ";
    print(vector);

    vector = { 5, 10, 6, 4, 3, 2, 6, 7, 9, 3 };
    std::cout << "Current vector is: ";
    print(vector); 

    // Using the nth_element algorithm
    auto it4 = vector.begin() + vector.size() / 2;
    std::nth_element(vector.begin(), it4, vector.end());
    std::cout << "The median is " << vector[std::size(vector) / 2] << '\n';
    // The consequence of the inequality of elements before/after the Nth one:
    std::cout << "Vector after using the nth_element algorithm: ";
    print(vector);
    // Comp function changed
    std::nth_element(vector.begin(), vector.begin() + 1, vector.end(), std::greater{});
    std::cout << "The second largest element is " << vector[1] << '\n';
    std::cout << "The largest element is " << vector[0] << '\n';
    std::cout << "Vector after using the nth_element algorithm and new comparator: ";
    print(vector);

    //Rotating the first two elements to the end
    std::rotate(std::begin(vector), std::begin(vector) + 2, std::end(vector));
    std::cout << "Vector after rotating the elements: ";
    print(vector);

    return 0;
}
