#include <iostream>

auto size_of_args() {
    return "No arguments";
}

template <typename... Types>
auto size_of_args(Types... args) {
    return (... + sizeof(args));
}

auto total_memory_size_no_fold() {
    return "No arguments";
}

template <typename T>
auto total_memory_size_no_fold(T arg) {
    return sizeof(arg);
}

template <typename T, typename... Types>
auto total_memory_size_no_fold(T arg, Types... args) {
    return sizeof(arg) + total_memory_size_no_fold(args...);
}

int main() {
    int a = 10;
    double b = 3.14;
    char c = 'A';
    std::string str = "Hello";

    auto size1 = size_of_args(a, b, c, str);
    std::cout << "Total size (size_of_args): " << size1 << std::endl;

    auto size2 = total_memory_size_no_fold(a, b, c, str);
    std::cout << "Total size (total_memory_size_no_fold): " << size2 << std::endl;

    auto size3 = size_of_args();
    std::cout << "Total size (size_of_args): " << size3 << std::endl;

    auto size4 = total_memory_size_no_fold();
    std::cout << "Total size (total_memory_size_no_fold): " << size4 << std::endl;

    return 0;

}