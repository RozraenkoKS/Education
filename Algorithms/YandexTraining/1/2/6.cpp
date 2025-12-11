#include <iostream>
#include <vector>

bool is_symmetric(const auto& v);

std::vector<int> f(auto N, const auto& v){
    std::vector<int> ans;
    auto i = 0;

    while (not is_symmetric(auto (v.begin + i, v.end))){
        ans.push_back(a[i]);
        ++i;
    }
}

int main(){
    int N;
    std::cin >> N;
    std::vector <int> v(N);
    for (auto i = 0; i < N; ++i){
        std::cin >> v[i];
    }
    for (auto x: f(N, v)){
        std::cout << x << ' ';
    }
}

// def main(N, a):
//     ans = []
//     i = 0
    
//     while not is_symmetric(a[i:]):
//         ans.append(a[i])
//         i += 1
        
//     print(len(ans))
//     return ans[::-1]
    
// if __name__ == '__main__':
//     N = int(input())
//     a = list(map(int, input().split()))
    
//     for x in main(N, a):
//         print(x, end=' ')