#include <iostream>
#include <string>
#include <unordered_map>

int main(){

    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::unordered_map<char, int> count;
    for (auto j = 0; j < n; ++j){
        count[s[j]] += 1;
    }
    auto i = 0, j = n - 1;
    while (count[s[i]] > k){
        --count[s[i]];
        ++i;
    }

    while (count[s[j]] > k){
    --count[s[j]];
    --j;
    }

    std::cout << j - i + 1 << ' ' << i + 1;
}