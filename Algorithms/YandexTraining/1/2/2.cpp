#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

auto counter(auto x, auto y, auto& counts) {
    if (x < y) {
        counts["ASCENDING"]++;
        counts["WEAKLY ASCENDING"]++;
    } else if (x == y) {
        counts["CONSTANT"]++;
        counts["WEAKLY ASCENDING"]++;
        counts["WEAKLY DESCENDING"]++;
    } else { 
        counts["DESCENDING"]++;
        counts["WEAKLY DESCENDING"]++;
    }
}

auto answer(const auto& counts, auto len) {
    if (counts.at("CONSTANT") == len - 1) return "CONSTANT";
    else if (counts.at("ASCENDING") == len - 1) return "ASCENDING";
    else if (counts.at("WEAKLY ASCENDING") == len - 1) return "WEAKLY ASCENDING";
    else if (counts.at("DESCENDING") == len - 1) return "DESCENDING";
    else if (counts.at("WEAKLY DESCENDING") == len - 1) return "WEAKLY DESCENDING";
    else return "RANDOM";
}

auto main_logic(const auto& a) {
    auto len = a.size();
    std::unordered_map<std::string, int> counts = {
        {"CONSTANT", 0},
        {"ASCENDING", 0},
        {"WEAKLY ASCENDING", 0},
        {"DESCENDING", 0},
        {"WEAKLY DESCENDING", 0}
    };

    for (auto i = 1; i < len; ++i) {
        counter(a[i - 1], a[i], counts);
    }

    return answer(counts, len);
}

int main() {
    std::vector<double> a;
    double x;
    
    while (std::cin >> x and x != -2000000000) {
        a.push_back(x);
    }

    if (!a.empty()) {
        std::cout << main_logic(a) << "\n";
    }

    return 0;
}
