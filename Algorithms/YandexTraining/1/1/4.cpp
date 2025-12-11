#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (c < 0) {
        std::cout << "NO SOLUTION\n";
    } else {
        if (a == 0) {
            if (b == c * c) {
                std::cout << "MANY SOLUTIONS\n";
            } else {
                std::cout << "NO SOLUTION\n";
            }
        } else {
            int y = c * c - b;
            int x = a;
            if (y % x == 0) {
                std::cout << y / x << "\n";
            } else {
                std::cout << "NO SOLUTION\n";
            }
        }
    }

    return 0;
}
