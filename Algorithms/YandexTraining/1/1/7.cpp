#include <iostream>

int main_calc(int n, int k, int m) {
    if (m > k) return 0;

    int details = 0;
    int left = n;
    int m_q = k / m;

    while (left >= k) {
        int k_q = left / k;
        details += m_q * k_q;
        left = left - k_q * k + (k - m_q * m) * k_q;
    }

    return details;
}

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::cout << main_calc(n, k, m) << "\n";
    return 0;
}