#include <iostream>
#include <string>
#include <random>
#include <unordered_set>
#include <vector>

[[nodiscard]] constexpr auto hash(const char* str, unsigned int length) {
    unsigned int hash = 0xAAAAAAAA;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash ^= ((i & 1) == 0) ? ((hash << 7) ^ (*str) * (hash >> 3)) :
            (~((hash << 11) + ((*str) ^ (hash >> 5))));
    }

    return hash;
}


[[nodiscard]] auto generateRandomStrings(std::size_t count, std::size_t size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis('a', 'z');

    std::unordered_set<std::string> uniqueStrings;

    while (uniqueStrings.size() < count) {
        auto randchar = [&]() -> char {
            return static_cast<char>(dis(gen));
            };
        std::string str(size, 0);
        std::generate_n(str.begin(), size, randchar);
        uniqueStrings.insert(str);
    }

    return uniqueStrings;
}


[[nodiscard]] constexpr auto measureCollisions(const std::unordered_set<std::string>& uniqueStrings, F hashFunction) {
    std::unordered_set<unsigned int> hashSet;
    int counter = 0;

    for (const auto& str : uniqueStrings) {
        unsigned int current_hash = hashFunction(str.c_str(), str.size());

        counter += !hashSet.insert(current_hash).second;
    }

    return counter;
}

int main() {
    constexpr std::size_t minCount = 100000;
    constexpr std::size_t maxCount = 200000;
    constexpr std::size_t step = 100000;
    constexpr std::size_t size = 10;
    std::vector<int> result;

    for (auto count = minCount; count <= maxCount; count += step) {
        auto uniqueStrings = generateRandomStrings(count, size);
        auto collisions = measureCollisions(uniqueStrings, hash);
        result.push_back(collisions);

    }

    for (const auto& entry : result) {
        std::cout << entry << ", ";
    }

    return 0;
}


