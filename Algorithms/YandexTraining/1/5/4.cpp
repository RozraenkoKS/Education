#include <iostream>
#include <vector>

int main(){
    int n, r;
    std::cin >> n >> r;
    std::vector<int> d(n);
    for (auto i = 0; i < n; ++i){
        std::cin >> d[i];
    }

    long long ans = 0;
    auto i = 0, j = 1;
    while (i < n && j < n){
        if (d[j] - d[i] <= r){
            j += 1;
        } else{
            ans += n - j;
            i += 1;
        }
    }
    std::cout << ans;
    return 0;
}