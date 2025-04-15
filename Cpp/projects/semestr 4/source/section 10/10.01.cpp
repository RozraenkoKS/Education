#include <iostream>
#include <source_location>

class Logger {
public:
    Logger(const std::source_location location = std::source_location::current()) : m_location(location) {
        std::clog << "file: "
            << m_location.file_name() << '('
            << m_location.line() << ':'
            << m_location.column() << ") `"
            << "The function "
            << m_location.function_name() << " execution has started"
            << '\n';
    };

    ~Logger() noexcept {
        std::clog << "file: "
            << m_location.file_name() << '('
            << m_location.line() << ':'
            << m_location.column() << ") `"
            << "The function "
            << m_location.function_name() << " execution has ended"
            << '\n';
    };

private:
    const std::source_location m_location{};
};

void example(const std::string& str) {
    Logger example_log{ std::source_location::current() };
    std::cout << str << "\n";
}

int main() {
    Logger main_log{ std::source_location::current() };
    example("example");
    return 0;
}