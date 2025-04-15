#include <exception>
#include <string>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <deque>
#include <array>
#include <forward_list>
#include <list>
#include <algorithm>
#include <numeric>


class Error : public std::exception {
public:
    explicit Error(const std::string& message) noexcept :
        std::exception(message.c_str()) {
    }
};

class Timer {
public:
    using clock_t = std::chrono::steady_clock;

    explicit Timer(std::string name) : m_name(std::move(name)), m_flag(false) {
        std::cout << "Timer " << m_name << " launched ... " << std::endl;
    }

    void elapsed() {
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(
            clock_t::now() - now).count() / 1'000'000.0;
        std::cout << "Timer " << m_name << " elapsed " << std::setprecision(6) <<
            std::fixed << time << " (seconds)" << std::endl;
        results.push_back(time);
    }

public:
    void start() {
        if (m_flag) {
            throw Error("Finish the timer first!");
        }
        now = clock_t::now();
        m_flag = true;
    }

    void stop() {
        if (!m_flag) {
            throw Error("Start the timer first!");
        }
        elapsed();
        m_flag = false;
    }

    bool is_counting() const noexcept {
        return m_flag;
    }

    double result() const {
        return std::accumulate(results.begin(), results.end(), 0.0) / results.size();
    }

private:
    std::vector<double> results;
    const std::string m_name;
    std::chrono::time_point<clock_t> now;
    bool m_flag;
};

template <auto N>
class Container_filling {
public:
    explicit Container_filling() noexcept : m_engine(m_rd()), distribution(0, 100000) {
    };
    void operator()(std::vector<int>& vector, std::deque<int>& deque, std::forward_list<int>& forward_list, std::list<int>& list, std::array<int, N>& array) {
        vector.clear();
        deque.clear();
        forward_list.clear();
        list.clear();

        for (auto i = 0; i < N; i++) {
            auto element = distribution(m_engine);
            vector.push_back(element);
            deque.push_back(element);
            list.push_back(element);
            array[i] = element;
        }
        for (auto i = 0; i < N; i++) {
            auto element = vector[N - i - 1];
            forward_list.push_front(element);
        }
    }
    void new_engine() {
        m_engine.seed(m_rd());
    }

private:
    std::random_device m_rd{};
    std::uniform_int_distribution<int> distribution;
    std::mt19937 m_engine{};
};

int main() {

    const std::size_t size = 100000;
    const std::size_t check_number = 200;

    std::vector<int> vector(size);
    std::deque<int> deque;
    std::forward_list<int> forward_list;
    std::list<int> list;
    std::array<int, size> array;

    Timer Vector{ "Vector" };
    Timer Deque{ "Deque" };
    Timer List{ "List" };
    Timer Forward_List{ "Forward_List" };
    Timer Array{ "Array" };

    std::cout << std::endl;

    Container_filling<size> container_filling {};

    for (auto i = 0; i < check_number; i++) {
        container_filling.new_engine();
        container_filling(vector, deque, forward_list, list, array);

        Vector.start();
        std::sort(vector.begin(), vector.end());
        Vector.stop();

        Deque.start();
        std::sort(deque.begin(), deque.end());
        Deque.stop();

        List.start();
        list.sort();
        List.stop();

        Forward_List.start();
        forward_list.sort();
        Forward_List.stop();

        Array.start();
        std::sort(array.begin(), array.end());
        Array.stop();
    }

    std::cout << std::endl;

    std::cout << "Average sorting time for vector: " << Vector.result() << '\n';
    std::cout << "Average sorting time for deque: " << Deque.result() << '\n';
    std::cout << "Average sorting time for list: " << List.result() << '\n';
    std::cout << "Average sorting time for forward list: " << Forward_List.result() << '\n';
    std::cout << "Average sorting time for array: " << Array.result() << '\n';

}
