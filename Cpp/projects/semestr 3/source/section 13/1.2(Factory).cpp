#include <iostream>
#include <memory>

class Computer {
public:
    virtual ~Computer() = default;
    virtual void run() const = 0;
};

struct Mobile : public Computer { void run() const override { std::cout << "Mobile" << std::endl; } };
struct Tablet : public Computer { void run() const override { std::cout << "Tablet" << std::endl; } };
struct Laptop : public Computer { void run() const override { std::cout << "Laptop" << std::endl; } };

template <typename T>
std::unique_ptr<Computer> create() {
    return std::make_unique<T>();
}

class Server : public Computer {
public:
    struct Factory {
        static std::unique_ptr<Computer> create_v1() { return std::make_unique<Server>(1); }
        static std::unique_ptr<Computer> create_v2() { return std::make_unique<Server>(2); }
        static std::unique_ptr<Computer> create_v3() { return std::make_unique<Server>(3); }
    };

    void run() const override { std::cout << "Server v" << m_version << std::endl; }

private:
    explicit Server(int version) : m_version(version) {}

    int m_version = 0;
};

class Factory {
public:
    virtual ~Factory() = default;
    [[nodiscard]] virtual std::unique_ptr<Computer> create() const = 0;
};

class Factory_Mobile : public Factory {
public:
    [[nodiscard]] std::unique_ptr<Computer> create() const override {
        return std::make_unique<Mobile>();
    }
};

class Factory_Tablet : public Factory {
public:
    [[nodiscard]] std::unique_ptr<Computer> create() const override {
        return std::make_unique<Tablet>();
    }
};

class Factory_Laptop : public Factory {
public:
    [[nodiscard]] std::unique_ptr<Computer> create() const override {
        return std::make_unique<Laptop>();
    }
};

int main() {
    auto mobile = create<Mobile>();
    mobile->run();

    auto server = Server::Factory::create_v1();
    server->run();

    auto factory_laptop = std::make_unique<Factory_Laptop>();
    auto laptop = factory_laptop->create();
    laptop->run();

    return 0;
}
