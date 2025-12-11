#include <iostream>
#include <vector>

bool check(int m, int n, int q, int c, const auto& a){

}

int lbinsearch(int l, int r, int n, int q, int c, const auto& a){
    while (l < r){
        int m = (l + r) / 2;
        if check(m, n, q, c, a){
            r = m;
        } else{
            l = m + 1;
        }
    }
    return l;
}

int main(){
    int n, q, c;
    std::vector <int> a;
    int x;
    int max{0};
    for (auto i = 0; i < n; ++i){
        std::cin >> x;
        a[i] = x;
        if (x > max){
            max = x;
        }
    }

    int l = 0;
    int r = max;

    std::cout << lbinsearch(l, r, n, q, c, a);
    return 0;
}