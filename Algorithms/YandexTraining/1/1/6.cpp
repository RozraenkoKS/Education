#include <iostream>
#include <algorithm> 

std::pair<int, int> minimal_rectangle(int a, int b, int c, int d) {
    int s1 = std::max(b, d) * (a + c);
    int s2 = std::max(b, c) * (a + d);
    int s3 = std::max(a, d) * (b + c);
    int s4 = std::max(a, c) * (b + d);

    int s = std::min({s1, s2, s3, s4});

    if (s == s2) {
        return {a + d, std::max(b, c)};
    } else if (s == s1) {
        return {a + c, std::max(b, d)};
    } else if (s == s3) {
        return {b + c, std::max(a, d)};
    } else {
        return {b + d, std::max(a, c)};
    }
}

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    auto [width, height] = minimal_rectangle(a, b, c, d);
    std::cout << width << " " << height << "\n";

    return 0;
}