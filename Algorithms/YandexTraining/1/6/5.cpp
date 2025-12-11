#include <iostream>

bool check(long long a, long long b, long long c, long long d){
    if (2 * (2 * a + 3 * b + 4 * c + 5 * d) >= 7 * (a + b + c + d)){
        return true;
    } else{
        return false;
    }
}

long long lbinsearch(long long l, long long r, long long a, long long b, long long c){
    while (l < r){
        long long m = (l + r) / 2;
        if (check(a, b, c, m)){
            r = m;
        }else {
            l = m + 1;
        }
    }
    return l;
}

int main(){
    long long a;
    long long b;
    long long c;

    std::cin >> a >> b >> c;
    long long l = 0;
    long long r = a + b + c;
    long long d = lbinsearch(l, r, a, b, c);
    std::cout << d;
    return 0;
}