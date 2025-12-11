#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> x(N + 1), y(N + 1);
    for (auto i = 1; i <= N; ++i) {
        std::cin >> x[i] >> y[i];
    }

    std::vector<int> up(N + 1, 0), down(N + 1, 0);
    for (auto i = 2; i <= N; ++i) {
        auto diff = y[i] - y[i - 1];
        up[i] = up[i - 1] + (diff > 0 ? diff : 0);
        down[i] = down[i - 1] + (diff < 0 ? -diff : 0);
    }

    int M;
    std::cin >> M;
    for (auto i = 0; i < M; ++i) {
        int s, f;
        std::cin >> s >> f;
        if (s < f) {
            std::cout << up[f] - up[s] << "\n";
        } else {
            std::cout << down[s] - down[f] << "\n";
        }
    }

    return 0;
}
