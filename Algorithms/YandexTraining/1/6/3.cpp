#include <iostream>
#include <algorithm>

inline bool check(long long m, long long n, long long w, long long h){
    long long a = m / w;
    long long b = m / h;
    long long prod = a * b;
    return prod >= n;
}

long long lbinsearch(long long l, long long r, long long w, long long h, long long n){
    while (l < r){
        long long m = (r + l) / 2;
        if (check(m, n, w, h)){
            r = m;
        } else{
            l = m + 1;
        }
    }
    return l;
}

int main(){
    long long w;
    long long h;
    long long n;
    std::cin >> w >> h >> n;

	long long r = (long long)1e18;
    std::cout << lbinsearch(1, r, w, h, n) << '\n';
    return 0;
}