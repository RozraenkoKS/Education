#include <iostream>
#include <vector>

int main() {

    int N, K;
    std::cin >> N >> K;
    std::vector<int> a(N+1);
    for (int i = 1; i <= N; ++i) std::cin >> a[i];

    std::vector<int> cnt(K+1, 0); 
    int have = 0;
    int l = 1;
    int bestL = 1, bestR = N;
    int bestLen = N + 1;

    for (int r = 1; r <= N; ++r) {
        if (++cnt[a[r]] == 1) ++have;

        while (have == K && l <= r) {
            if (r - l + 1 < bestLen) {
                bestLen = r - l + 1;
                bestL = l;
                bestR = r;
            }
            if (--cnt[a[l]] == 0) --have;
            ++l;
        }
    }

    std::cout << bestL << " " << bestR << "\n";
    return 0;
}
