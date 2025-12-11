#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib> 

int main() {
    int n;
    std::cin >> n;
    std::vector<int> shirts(n);
    for (auto i = 0uz; i < n; ++i) std::cin >> shirts[i];

    int m;
    std::cin >> m;
    std::vector<int> pants(m);
    for (auto i = 0uz; i < m; ++i) std::cin >> pants[i];

    auto i = 0uz, j = 0uz;
    auto mindiff = std::abs(shirts[0] - pants[0]);
    std::pair<int,int> ans{shirts[0], pants[0]};

    while (i < shirts.size() && j < pants.size()) {
        auto a = shirts[i];
        auto b = pants[j];
        auto diff = std::abs(a - b);

        if (diff < mindiff) {
            mindiff = diff;
            ans = {a, b};
        }

        if (a < b) i++;
        else j++;
    }

    std::cout << ans.first << " " << ans.second << "\n";
    return 0;
}
