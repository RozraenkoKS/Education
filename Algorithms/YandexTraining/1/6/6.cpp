#include <iostream>
#include <algorithm>

using ll = long long;

bool check(ll N, ll x, ll y, ll m) {
    m -= std::min(x, y);
    if (m < 0) return false;
    ll a = m / x;
    ll b = m / y;
    return (a + b + 1) >= N;
}

ll lbinsearch(ll l, ll r, ll N, ll x, ll y) {
    while (l < r) {
        ll m = (l + r) / 2;
        if (check(N, x, y, m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main() {

    ll N, x, y;
    std::cin >> N >> x >> y;

    if (N == 1) {
        std::cout << std::min(x, y);
        return 0;
    }

    ll l = 0;
    ll r = N * std::max(x, y);
    std::cout << lbinsearch(l, r, N, x, y);
}
