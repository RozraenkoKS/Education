#include <vector>
#include <iostream>
#include <algorithm>
#include <ranges>
#include <iomanip>

int main() {
    std::vector<int> v;
    std::vector<int> result;

    for (auto i = 1; i <= 1000; ++i) {
        v.push_back(0);
        result.push_back(v.capacity());
    }

    auto ret = std::ranges::unique(result);
    result.erase(ret.begin(), ret.end());

    std::cout << "Unique values capacity: ";
    for (auto element : result) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    std::vector<double> relation;
    for (auto it = result.begin(); it != result.end() - 1; it++) {
        relation.push_back(static_cast<double>(*(it + 1)) / *it);
    }
    std::cout << "The relations beetween allocated memory: ";
    for (auto element : relation) {
        std::cout << std::setprecision(3) << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}

/*Unique values capacity: 1 2 3 4 6 9 13 19 28 42 63 94 141 211 316 474 711 1066 1599 2398 3597 5395 8092 12138 18207 27310 40965 61447 92170 138255 207382 311073 466609 699913 1049869
The relations beetween allocated memory: 2 1.5 1.33 1.5 1.5 1.44 1.46 1.47 1.5 1.5 1.49 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5*/

