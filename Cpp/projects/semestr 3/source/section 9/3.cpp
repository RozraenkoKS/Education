#include <iostream>

class Base1
{
public:
    virtual void base1Function() = 0;
};

class Base2
{
public:
    virtual void base2Function() = 0;
};

class Derived : public Base1, public Base2
{
protected:
    explicit Derived(int x) {}

public:
    void base1Function() override { std::cout << "Base1 Function" << std::endl; }
    void base2Function() override { std::cout << "Base2 Function" << std::endl; }
};

template <typename T>
class Initializer : public T
{
public:
    template <typename... Types>
    explicit Initializer(Types... args) : T(args...)
    {
        this->initialize(); 
    }

    void initialize() { std::cout << "Initialization" << std::endl; }
};

int main()
{
    Initializer<Derived> derivedMixin(42);

    derivedMixin.base1Function();
    derivedMixin.base2Function();

    return 0;
}

