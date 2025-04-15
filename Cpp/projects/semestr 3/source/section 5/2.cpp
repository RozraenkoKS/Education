#include <iostream>

class Container {
public:
    using data_t = int;
    using size_t = int;

    Container() : m_data(nullptr), m_size(0), m_capacity(0) {
        std::cout << "default constructor" << std::endl;
    }

    Container(size_t size) : m_size(size), m_capacity(size) {
        std::cout << "main constructor" << std::endl;
        m_data = new data_t[m_capacity]{};
    }

    Container(const Container& other) : m_size(other.m_size), m_capacity(other.m_capacity) {
        std::cout << "copy constructor" << std::endl;
        m_data = new data_t[m_capacity]{};

        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    Container(Container&& other) : Container() {
        std::cout << "move constructor" << std::endl;
        swap(other);
    }

    Container& operator=(Container other) {
        std::cout << "copy and swap" << std::endl;
        swap(other);
        return *this;
    }

    void swap(Container& other) {
        using std::swap;
        swap(m_data, other.m_data);
        swap(m_size, other.m_size);
        swap(m_capacity, other.m_capacity);
    }

    ~Container() {
        std::cout << "destructor" << std::endl;
        if (m_data) {
            delete[] m_data;
        }
    }

    data_t& operator[](size_t index) {
        if (index < m_size) {
            return m_data[index];
        }
        return m_error_value;

    }

    const data_t& operator[](size_t index) const {
        if (index < m_size) {
            return m_data[index];
        }
        return m_error_value;
    }

    data_t& front() {
        if (m_size > 0) {
            return m_data[0];
        }
        return m_error_value;
    }

    const data_t& front() const {
        if (m_size > 0) {
            return m_data[0];
        }
        return m_error_value;
    }

    data_t& back() {
        if (m_size > 0) {
            return m_data[m_size - 1];
        }
        return m_error_value;
    }

    const data_t& back() const {
        if (m_size > 0) {
            return m_data[m_size - 1];
        }
        return m_error_value;
    }

    size_t getSize() const {
        return m_size;
    }

    size_t getCapacity() const {
        return m_capacity;
    }

    bool empty() const {
        return m_size == 0;
    }

    void clear() {
        m_size = 0;
    }

    void push_back(const data_t& value) {
        if (m_size == m_capacity) {
            size_t newCapacity = (m_capacity == 0) ? 1 : (m_capacity * 2);
            data_t* newData = new data_t[newCapacity]{};
            for (size_t i = 0; i < m_size; ++i) {
                newData[i] = m_data[i];
            }
            delete[] m_data;
            m_data = newData;
            m_capacity = newCapacity;
        }
        m_data[m_size++] = value;
    }

private:
    data_t* m_data;
    size_t m_size;
    size_t m_capacity;
    data_t m_error_value{-1};
};

void swap(Container& x, Container& y) {
    x.swap(y);
}

Container f() {
    return Container();
}

Container g() {
    Container c = Container();
    return c;
}

int main() {
    Container container(5);

    for (int i = 0; i < container.getSize(); ++i) {
        container[i] = i * 10;
    }

    for (int i = 0; i < container.getSize(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;

    container.push_back(50);
    container.push_back(60);

    for (int i = 0; i < container.getSize(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;

    std::cout << container[10];

    std::cout << std::endl;

    return 0;
}
