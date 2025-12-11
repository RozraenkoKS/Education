#include <iostream>
#include <vector>

auto f(const auto& v){
    if (v.empty()){
        return "NO";
    }
    for (auto i = 1; i < v.size(); ++i){
        if (v[i] <= v[i - 1]){
            return "NO";
        }
    }
    return "YES";
}

int main(){
    std::vector<int> v;
    int x;
    while(std::cin >> x) v.push_back(x);
    std::cout << f(v);
    return 0;
}