#include <iostream>
#include <deque>
#include <algorithm>
#include <stack>

class Error : public std::exception {
public:
    explicit Error(const std::string& message) noexcept :
        std::exception(message.c_str()) {
    }
};

template <typename T, class Container = std::deque<T>>
class advanced_stack {
public:
    advanced_stack() noexcept = default;

    [[nodiscard]] bool empty() const noexcept {
        return c.empty();
    }

    [[nodiscard]] std::size_t size() const noexcept {
        return c.size();
    }

    [[nodiscard]] T top() noexcept {
        return c.back();
    }

    [[nodiscard]] const T top() const noexcept {
        return c.back();
    }

    void push(const T& x) {
        if (c.empty()) {
            max = x;
            c.push_back(x);
            return;
        }
        if (x > max) {
            c.push_back(2 * x - max);
            max = x;
        }
        else
            c.push_back(x);
    }

    void pop() {
        if (c.empty()) {
            throw Error("The stack is already empty");
        }

        T t = c.back();
        c.pop_back();

        if (t > max) {
            max = 2 * max - t;
        }
    }

    void swap(advanced_stack& Right) noexcept {
        std::swap(c, Right.c);
        std::swap(max, Right.max);
    }

    [[nodiscard]] T max_element() const {
        return max;
    }

private:
    Container c{};
    T max;
};

int main() {
    advanced_stack<int> stack;

    stack.push(5);
    stack.push(3);
    stack.push(10);
    stack.push(7);

    std::cout << "Current max element: " << stack.max_element() << std::endl;

    stack.pop();
    stack.pop();

    std::cout << "Current max element after popping: " << stack.max_element() << std::endl;

    return 0;
}
