#include <regex>
#include <iostream>
#include <stdexcept>

std::string transform_date(std::string_view text) {
    auto rx = std::regex{ R"((0[1-9]|[12]\d|30|31)\.(0[1-9]|1[0-2])\.(\d{4}|\d{2}))" };
    std::string result = std::regex_replace(text.data(), rx, R"($1/$2/$3)");

    if (result == text)
        throw std::invalid_argument("No date found for replacement");

    return result + '\n';
}

int main() {
    using namespace std::literals;
    try {
        std::cout << transform_date("today is 31.12.2017!"s);
        std::cout << transform_date("today is 32.12.2017!"s);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


