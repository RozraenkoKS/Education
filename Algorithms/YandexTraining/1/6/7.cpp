#include <iostream>
#include <algorithm>

using ll = long long;

bool check(ll n, ll m, ll t, ll d){
    ll inner_n = std::max(0LL, n - 2*d);
    ll inner_m = std::max(0LL, m - 2*d);
    return (n * m - inner_n * inner_m <= t);
}

ll rbinsearch(ll l, ll r, ll n, ll m, ll t){
    while (l < r){
        ll d = (l + r + 1) / 2;
        if (check(n, m, t, d)){
            l = d;
        } else{
            r = d - 1;
        }
    }
    return l;
}

int main(){

    ll n, m, t;
    std::cin >> n >> m >> t;

    ll l = 0;
    ll r = std::max(n, m);

    std::cout << rbinsearch(l, r, n, m, t);
    return 0;
}