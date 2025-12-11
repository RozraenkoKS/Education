#include <vector>
#include <iostream>

auto closest(int n, const std::vector<long long>& a, long long x){
    auto l = 0, r = n - 1;
    while (r - l > 1){
        auto m = (l + r + 1) / 2;
        if (a[m] > x){
            r = m;
        } else{
            l = m;
        }
    }
    if (std::abs(a[r] - x) < std::abs(a[l] - x)){
        return a[r];
    } else{
        return a[l];
    }

}

int main(){
    int n, k;
    std::cin >> n >> k;

    std::vector<long long> a(n);
    for (auto i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    long long x;
    for(auto i = 0; i < k; ++i){
        std::cin >> x;
        std::cout << closest(n, a, x) << '\n';
    }

    return 0;
}