#include <vector>
#include<iostream>

auto isin(int n, const std::vector<int>& a, int x){
    auto l = 0, r = n - 1;
    while (l < r){
        auto m = (l + r + 1) / 2;
        if (a[m] > x){
            r = m - 1;
        } else{
            l = m;
        }
    }
    return a[l] == x;

}

int main(){
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (auto i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    int x;
    for(auto i = 0; i < k; ++i){
        std::cin >> x;
        std::cout << (isin(n, a, x) ? "YES" : "NO") << '\n';
    }

    return 0;
}

