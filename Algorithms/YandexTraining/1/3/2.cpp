#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss1(line);
    std::unordered_set<int> s1;
    int x;
    while (iss1 >> x) s1.insert(x);

    std::getline(std::cin, line);
    std::istringstream iss2(line);
    std::unordered_set<int> inter;
    while (iss2 >> x) {
        if (s1.find(x) != s1.end()) inter.insert(x);
    }

    std::vector<int> ans(inter.begin(), inter.end());
    std::sort(ans.begin(), ans.end());

    for (size_t i = 0; i < ans.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << ans[i];
    }
    std::cout << '\n';
    return 0;
}
