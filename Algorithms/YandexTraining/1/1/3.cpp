#include <iostream>
#include <string>

std::string normalize(const std::string& s) {
    std::string digits;
    for (auto c : s) {
        if (c >= '0' && c <= '9') {
            digits.push_back(c);
        }
    }

    if (digits.size() == 7) {
        digits = "495" + digits;
    }
    if (digits.size() == 11) {
        digits.erase(0, 1); // удалить первый символ
    }

    return digits;
}

int main() {
    std::string s0, s1, s2, s3;

    std::cin >> s0 >> s1 >> s2 >> s3;

    s0 = normalize(s0);
    s1 = normalize(s1);
    s2 = normalize(s2);
    s3 = normalize(s3);

    std::cout << (s1 == s0 ? "YES" : "NO") << '\n';
    std::cout << (s2 == s0 ? "YES" : "NO") << '\n';
    std::cout << (s3 == s0 ? "YES" : "NO") << '\n';

    return 0;
}
