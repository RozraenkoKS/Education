#include <iostream>
#include <algorithm>

bool check(long long n, long long a, long long b, long long w, long long h, long long d){
    long long x1 = w / (a + 2 * d);
    long long y1 = h / (b + 2 * d);
    long long x2 = h / (a + 2 * d);
    long long y2 = w / (b + 2 * d);
    if (x1 * y1 >= n or x2 * y2 >= n){
        return true;
    } else{
        return false;
    }
}

inline long long rbinsearch(long long l, long long r, long long n, long long a, long long b, long long w, long long h){
    while (l < r){
        long long m = (l + r + 1) / 2;
        if (check(n, a, b, w, h, m)){
            l = m;
        } else {
            r = m - 1;
        }
    }
    return l;
}

int main(){
    long long n, a, b, w, h;
    std::cin >> n >> a >> b >> w >> h;
    long long l = 0;
    long long r = std::max(w, h);
    long long d = rbinsearch(l, r, n, a, b, w ,h);
    std::cout << d;
    return 0;
}