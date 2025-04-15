#include <iostream>

int main() {
}

#define MESSAGE "Any message"

int message_function() {
    std::cout << MESSAGE;
    return 0;
}

int A = message_function();