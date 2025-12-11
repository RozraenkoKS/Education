#include <iostream>
#include <unordered_set>
#include <utility>
#include <string>

auto get_p_n(int k, int m, int apparts_floor){
    int p = (k - 1) / (apparts_floor * m) + 1;
    int n = (k - (p - 1) * apparts_floor * m - 1) / apparts_floor + 1;

    return std::pair<int, int>(p, n);
}

std::string decision(int k1, int m ,int k2, int p2, int n2){
    std::unordered_set<int> results_p{};
    std::unordered_set<int> results_n{};
    int apparts_floor = 1;
    while(apparts_floor * (m * (p2 - 1) + (n2 - 1)) < k2 and apparts_floor < 100000){
        auto [p, n] = get_p_n(k2, m, apparts_floor);
        if (p2 == p and n2 == n){
            auto [p1, n1] = get_p_n(k1, m, apparts_floor);
            results_p.insert(p1);
            results_n.insert(n1);
        }
        apparts_floor += 1;
    }
    if (results_p.empty()){
        return "-1 -1";
    }
    else{
        return std::to_string(results_p.size() > 1 ? 0 : *results_p.begin()) + " " + std::to_string((m == 1) ? 1 : (results_n.size() > 1 ? 0 : *results_n.begin()));
    }
}

int main(){
    int k1;
    int k2;
    int m;
    int p2;
    int n2;
    std::cin >> k1 >> m >> k2 >> p2>> n2;
    std::cout << decision(k1, m, k2, p2, n2);
    return 0;
}
