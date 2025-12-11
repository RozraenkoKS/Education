#include <iostream>
#include <vector>
#include <algorithm>

constexpr auto MAX_P = 1000;
constexpr auto INF = 1001;

int main(){

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    int x;
    for (auto i = 0; i < n; ++i){
        std::cin >>a[i];
    }

    int m;
    std::cin >> m;

    std::vector<int> min_cost(MAX_P + 2, INF);
    for (auto i = 0; i < m; ++i){
        int b, c;
        std::cin >> b >> c;
        min_cost[b] = std::min(min_cost[b], c);
    }
    
    for (auto p = MAX_P; p >= 1; --p){
        min_cost[p] = std::min(min_cost[p], min_cost[p + 1]);
    }

    long long ans = 0;
    for (auto i = 0; i < n; ++i){
        ans += min_cost[a[i]];
    }

    std::cout << ans;
    return 0;
}