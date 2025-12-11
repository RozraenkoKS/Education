 #include <iostream>
 #include <vector>
 #include <map>
 #include <algorithm>

 int main(){
    int n;
    int k;
    std::cin >> n >> k;
    
    std::map<int, int> count;
    std::vector<int> keys;
    int x;
    for (auto i = 0; i < n; ++i){
        std::cin >> x;
        count[x] += 1;
    }
    for (auto [key, value]: count){
        keys.push_back(key);
    }
    auto m = keys.size();

    for (auto i = 0; i < m; ++i){
        long long num = 0;
        long long den = 1;
        auto thr = count[keys[i]] * 2;
        auto j = i;
        while (keys[j] <= thr){
            num += count[keys[j]];
            den *= std::factorial(keys[j]);
            ++j;
        }

    }
}
