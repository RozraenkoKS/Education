#include <iostream>

template < typename T, auto N >
class Container {
public:
    using size_t = decltype(N);
public:
    Container() : m_data(nullptr), m_size(0), m_capacity(0) {
        std::cout << "default constructor" << std::endl;
    }

    Container(size_t size) : m_size(size), m_capacity(size) {
        std::cout << "main constructor" << std::endl;
        m_data = new T[m_capacity]{};
    }

    Container(const Container& other) : m_size(other.m_size), m_capacity(other.m_capacity) {
        std::cout << "copy constructor" << std::endl;
        m_data = new T[m_capacity]{};

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

    T& operator[](size_t index) {
        return m_data[index];
    }

    const T& operator[](size_t index) const { 
        return m_data[index];
    }

    T& front() {
        return m_data[0];
    }

    const T& front() const { 
        return m_data[0];
    }

    T& back() {
        return m_data[m_size - 1];
    }

    const T& back() const {
        return m_data[m_size - 1];
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

    void push_back(const T& value) {
        if (m_size == m_capacity) {
            size_t newCapacity = (m_capacity == 0) ? 1 : (m_capacity * 2);
            T* newData = new T[newCapacity]{};
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
    T* m_data;
    size_t m_size;
    size_t m_capacity;
};

template <typename T>
void swap(DynamicContainer<T>& x, DynamicContainer<T>& y) {
    x.swap(y);
};

#include <iostream>

int main() {
    Container<int, 5> myContainer(5);

    for (int i = 0; i < myContainer.getSize(); ++i) {
        myContainer[i] = i * 10;
    }

    std::cout << "Container elements: ";
    for (int i = 0; i < myContainer.getSize(); ++i) {
        std::cout << myContainer[i] << " ";
    }
    std::cout << std::endl;

    for (int i = myContainer.getSize(); i < 10; ++i) {
        myContainer.push_back(i * 10);
    }

    std::cout << "Container elements after push_back: ";
    for (int i = 0; i < myContainer.getSize(); ++i) {
        std::cout << myContainer[i] << " ";
    }
    std::cout << std::endl;

    Container<int, 10> anotherContainer(myContainer);

    std::cout << "Copied Container elements: ";
    for (int i = 0; i < anotherContainer.getSize(); ++i) {
        std::cout << anotherContainer[i] << " ";
    }
    std::cout << std::endl;

    swap(myContainer, anotherContainer);

    std::cout << "Container elements after swapping: ";
    for (int i = 0; i < myContainer.getSize(); ++i) {
        std::cout << myContainer[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Copied Container elements after swapping: ";
    for (int i = 0; i < anotherContainer.getSize(); ++i) {
        std::cout << anotherContainer[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}