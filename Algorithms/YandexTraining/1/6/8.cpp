#include <iostream>
#include <vector>

using ll = long long;

bool check(int k, ll m, const std::vector<ll>& a){
    ll num = 0;                   
    for (auto x : a){
        num += x / m;
    }
    return num >= k;
}

ll rbinsearch(ll l, ll r, int k, const std::vector<ll>& a){
    while (l < r){
        ll m = (l + r + 1) / 2;  
        if (check(k, m, a)){
            l = m;
        } else{
            r = m - 1;
        }
    }
    return l;
}

int main(){
    int n, k;
    if (!(std::cin >> n >> k)) return 0;

    ll l_max = 0;
    ll x;
    std::vector<ll> a(n);
    ll total_sum = 0;              
    for (int i = 0; i < n; ++i){
        std::cin >> x;
        a[i] = x;
        total_sum += x;
        if (x > l_max) l_max = x;
    }

    if (total_sum < k){
        std::cout << 0;
        return 0;
    }

    ll l = 1;
    ll r = l_max;

    std::cout << rbinsearch(l, r, k, a);
    return 0;
}
