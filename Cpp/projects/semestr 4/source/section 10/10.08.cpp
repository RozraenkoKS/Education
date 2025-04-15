#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

class Error : public std::exception {
public:
    explicit Error(const std::string& message) :
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
        if (results.empty()) {
            return 0.0;
        }
        return std::accumulate(results.begin(), results.end(), 0.0) / results.size();
    }

    void clearResults() {
        results.clear();
    }


private:
    std::vector<double> results;
    const std::string m_name;
    std::chrono::time_point<clock_t> now;
    bool m_flag;
};

int main() {
    constexpr std::size_t minSize = 1024;
    constexpr std::size_t maxSize = 1024 * 1024 * 1024;
    constexpr std::size_t stepSize = 1024 * 1024;

    Timer clockNew("NewTimer");
    Timer clockDelete("DeleteTimer");

    for (auto size = minSize; size <= maxSize; size += stepSize) {
        std::cout << "For size " << size << ":" << '\n';

        clockNew.start();
        auto* ptr = ::operator new(size);
        clockNew.stop();

        std::cout << "Current ptr is: " << ptr << '\n';

        clockDelete.start();
        ::operator delete(ptr);
        clockDelete.stop();
    }

    return 0;
}
