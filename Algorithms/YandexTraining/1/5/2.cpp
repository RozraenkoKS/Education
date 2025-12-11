#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (auto i = 0; i < n; ++i) std::cin >> a[i];

    std::unordered_map<int, int> count {{0, 1}}; 
    auto s = 0;
    auto ans = 0;

    for (auto x : a) {
        s += x;
        ans += (count.find(s - k) != count.end() ? count[s - k] : 0);
        count[s]++; 
    }

    std::cout << ans << "\n";
}
