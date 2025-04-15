
#include <cassert>
#include <cstddef>
#include <type_traits>
#include <utility>

template < typename T>
class Unique // note: no custom deleters support
{
public:

    Unique() noexcept = default;

    explicit Unique(T* data) noexcept : m_data(data) {} // good: explicit

    template <typename U>
    Unique(Unique<U>&& other) noexcept : m_data(other.release()) {}

    Unique(const Unique&) noexcept = delete;

    Unique(Unique&& other) noexcept : Unique() { swap(other); }

    ~Unique() noexcept { reset(); }

public:

    Unique& operator=(const Unique&) noexcept = delete;

    Unique& operator=(Unique&& other) noexcept
    {
        reset(other.release()); return *this;
    }
    operator bool() const {
        return m_data;
    }


public:

    void swap(Unique& other) noexcept
    {
        using std::swap; // good: enable argument-dependent lookup

        swap(m_data, other.m_data);
    }

    [[nodiscard]] T* release() noexcept
    {
        return std::exchange(m_data, nullptr);
    }

    void reset(T* ptr = nullptr) noexcept
    {
        delete std::exchange(m_data, ptr); // note: consider custom deleter
    }

public:

    [[nodiscard]] T& operator*() const noexcept { return *m_data; }
    [[nodiscard]] T* operator->() const noexcept { return m_data; }

public:
    T* get() const {
        return m_data;
    }

private:

    T* m_data = nullptr;

}; // template < typename T > class Unique

template < typename T > void swap(Unique < T >& lhs, Unique < T >& rhs) noexcept
{
    lhs.swap(rhs);
}

template <typename T, typename... Args>
Unique<T> make_unique(Args&&... args) {
    return Unique<T>(new T(std::forward<Args>(args)...));
}

int main()
{
    Unique < int > unique_1(new int(42));
    Unique < int > unique_2(new int(43));

    unique_2 = std::move(unique_1);

    assert(*unique_2 == 42);

    return 0;
}

