#include <algorithm>
#include <array>
#include <iostream>

int main() {
    const auto v = { 1, 2, 3, 4 };

    for (const int n : {4, 5})
        (std::find(v.begin(), v.end(), n) == std::end(v))
        ? std::cout << "v does not contain " << n << '\n'
        : std::cout << "v contains " << n << '\n';
    std::cout << *(std::end(v) - 1) << '\n';
}