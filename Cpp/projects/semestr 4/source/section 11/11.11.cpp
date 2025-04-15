#include <set>
#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <numeric>

[[nodiscrad]] void set_function(std::size_t size, std::set<int>& set, std::random_device::result_type seed) {
    std::mt19937 engine(seed);
    std::uniform_int_distribution distribution(1, 999);

    for (auto i = 0; i < size; ++i) {
        set.insert(distribution(engine));
    }
}

[[nodiscrad]] void vector_function(std::size_t size, std::vector<int>& vector, std::random_device::result_type seed) {
    std::mt19937 engine(seed);
    std::uniform_int_distribution distribution(1, 999);

    for (auto i = 0; i < size; ++i) {
        vector.push_back(distribution(engine));
    }
    std::sort(vector.begin(), vector.end());
}

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

int main() {
    const std::size_t size{ 1000000 };
    std::set<int> set;
    std::vector<int> vector;
    vector.reserve(size);

    Timer clockSet("Set Timer");
    Timer clockVector("Vector Timer");

    std::random_device rd;

    for (auto i = 0; i < 100; i++) {
        auto seed = rd();
        clockSet.start();
        set_function(size, set, seed);
        clockSet.stop();

        clockVector.start();
        vector_function(size, vector, seed);
        clockVector.stop();

        vector.clear();
        set.clear();
    }

    std::cout << "Average time for set_function: " << clockSet.result() << " seconds" << std::endl;
    std::cout << "Average time for vector_function: " << clockVector.result() << " seconds" << std::endl;

    return 0;
}

/*Average time for set_function: 0.057562 seconds
Average time for vector_function: 0.036862 seconds
Set's constant is approximately x1.5 vector's constant
If you know in advance of many elements to expect, you can reserve() the space in your vector to avoid reallocations, making the first choice very interesting (fast insertions, single sort).

If you need to do it once, go for the std::vector<>. If other insertions will occur later in the program, the std::set<> might be more interesting.

If you don't know the expected size in advance, then reallocations may occur with the vector, and std::set<> is a good choice (better theoretical average complexity).

O(n) + O(n * log(n)) for the vector vs O(n * log(n)) for the set

If the number of elements is very small, you still can reserve some space (e.g. if you expect 10 elements, you might reserve 100 to be safe), and go with the std::vector

Anyway, profiling both solutions is always a good practice, the actual result will depend (among other things) of the initial sorting state of the input, and on the quality of your implementation for each container.*/
